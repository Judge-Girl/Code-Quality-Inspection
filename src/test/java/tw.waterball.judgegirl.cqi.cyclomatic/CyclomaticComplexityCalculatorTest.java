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

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.File;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.*;

class CyclomaticComplexityCalculatorTest {
    private CyclomaticComplexityCalculator calculator;
    private Object HashSet;

    @BeforeEach
    void setup() {
        calculator = new CyclomaticComplexityCalculatorImpl();
    }

    @Test
    void test() throws IOException, InterruptedException {
        List<String> sourceCodes = new ArrayList<>();
        String basePath = "C:/Users/user/Desktop/lab/judge/";
        Scanner sc = new Scanner(new File(basePath + "result"));
        int total = 0;
        while(sc.hasNext()) {
            String filename = sc.next();
            Integer expected = sc.nextInt();
            String sourceCode = Files.readString(Paths.get(basePath + filename));
            sourceCodes.add(sourceCode);
            int score = calculator.calculate(new ArrayList<>(Collections.singleton(sourceCode))).score;
            System.out.println(filename + " " + expected + " " + score);
            assertEquals(expected, score);
            total += score;
        }
        CyclomaticComplexityReport report = calculator.calculate(
                sourceCodes
        );
        //System.out.println(report.score);
        assertEquals(total, report.score);
    }
}