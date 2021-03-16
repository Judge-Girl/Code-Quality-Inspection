/*
 * Copyright 2020 Johnny850807 (Waterball) 潘冠辰
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *       http://www.apache.org/licenses/LICENSE-2.0
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

package tw.waterball.judgegirl.cqi.main;

import tw.waterball.judgegirl.cqi.csa.CodingStyleAnalyzeReport;
import tw.waterball.judgegirl.cqi.csa.CodingStyleAnalyzer;
import tw.waterball.judgegirl.cqi.csa.CodingStyleAnalyzerImpl;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityCalculatorImpl;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityCalculator;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityReport;


import java.io.File;
import java.nio.file.Path;
import java.util.List;
import java.util.ArrayList;

public class Main{

    public static void main(String[] args){
        if(args.length!=1){
            System.out.println("Expected one argument: sourceRootPathString.");
            return;
        }
        String sourceRootPathString = args[0];
        Path sourceRootPath = Path.of(sourceRootPathString);
        File folder = sourceRootPath.toFile();
        File[] fileList = folder.listFiles();
        List<String> sourceCodes = new ArrayList<>();
        for(int i = 0; i < fileList.length; i++) {
            sourceCodes.add(fileList[i].getPath());
        }
        CyclomaticComplexityCalculator calculator = new CyclomaticComplexityCalculatorImpl();
        CyclomaticComplexityReport ccReport = calculator.calculate(sourceCodes);
        CodingStyleAnalyzer analyzer = new CodingStyleAnalyzerImpl();
        CodingStyleAnalyzeReport csaReport = analyzer.analyze(sourceRootPathString);
        System.out.println(ccReport.score);
        System.out.println(csaReport.getScore());
    }
}
