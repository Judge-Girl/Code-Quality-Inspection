/*
 * Copyright 2020 Johnny850807 (Waterball) 潘冠辰
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package tw.waterball.judgegirl.cqi.cyclomatic;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.nio.charset.StandardCharsets;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.List;
import java.io.OutputStreamWriter;
import java.lang.ProcessBuilder;
import java.lang.Process;



/**
 * @author - ryan01234keroro56789@gmail.com (Giver)
 */
public class CyclomaticComplexityCalculatorImpl implements CyclomaticComplexityCalculator {

    @Override
    public CyclomaticComplexityReport calculate(List<String> sourceCodes) {
        return new CyclomaticComplexityReport(
                sourceCodes.stream()
                .mapToInt(this::calculateSingleCode)
                .sum()
        );
    }

    private int calculateSingleCode(String sourceCode) {
        sourceCode = preprocess(sourceCode);
        return calculateCCScore(sourceCode) - calculateCCInStringLiterals(sourceCode);
    }

    private String preprocess(String sourceCode) {
        sourceCode = sourceCode.replaceAll("\r","");
        sourceCode = removePattern(sourceCode, "\n[ \t]*#[ \t]*include[^\n]*");
        sourceCode = callCPreprocessor(sourceCode);
        sourceCode = removePattern(sourceCode, "\n# [0-9]+ [^\n]*");
        sourceCode = removePattern(sourceCode, "^[ \t\n]*");
        return sourceCode;
    }

    private String removePattern(String code, String patternString){
        return ("\n" + code).replaceAll(patternString, "");
    }

    private String callCPreprocessor(String sourceCode) {
        ProcessBuilder pb = new ProcessBuilder("cpp");
        Process proc;
        try{
             proc = pb.start();
        } catch(IOException err) {
            throw new RuntimeException(err);
        }
        try (OutputStreamWriter osw = new OutputStreamWriter(proc.getOutputStream())) {
            osw.write(sourceCode, 0, sourceCode.length());
        } catch(IOException err) {
            throw new RuntimeException(err);
        }
        try{
            sourceCode = new String(proc.getInputStream().readAllBytes(), StandardCharsets.UTF_8);
        } catch(IOException err) {
            throw new RuntimeException(err);
        }
        try{
            proc.waitFor();
        } catch(InterruptedException err) {
            throw new RuntimeException(err);
        }
        return sourceCode;
    }

    private int calculateCCScore(String sourceCode) {
        String patternString = "([^0-9A-Za-z_]((if)|(case)|(for)|(while)|(catch))[^0-9A-Za-z_])|[&][&]|[|][|]|[?]";
        Pattern pattern = Pattern.compile(patternString);
        Matcher matcher = pattern.matcher(sourceCode);
        int counter = 0;
        while(matcher.find()) {
            counter++;
        }
        return counter;
    }

    private int calculateCCInStringLiterals(String code) {
        String patternString = "\"(\\.|[^\"\n])*\"";
        Pattern pattern = Pattern.compile(patternString);
        Matcher matcher = pattern.matcher(code);
        int counter = 0;
        while(matcher.find()) {
            counter += calculateCCScore(matcher.group());
        }
        return counter;
    }

}
