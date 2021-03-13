///*
// * Copyright 2020 Johnny850807 (Waterball) 潘冠辰
// * Licensed under the Apache License, Version 2.0 (the "License");
// * you may not use this file except in compliance with the License.
// * You may obtain a copy of the License at
// *     http://www.apache.org/licenses/LICENSE-2.0
// * Unless required by applicable law or agreed to in writing, software
// * distributed under the License is distributed on an "AS IS" BASIS,
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// * See the License for the specific language governing permissions and
// * limitations under the License.
// */
//
//package tw.waterball.judgegirl.cqi.cyclomatic;
//
//import org.junit.jupiter.api.BeforeEach;
//import org.junit.jupiter.api.Test;
//
//import java.io.IOException;
//import java.nio.file.Paths;
//import java.nio.file.Files;
//import java.io.File;
//import java.util.Collections;
//import java.util.List;
//import java.util.ArrayList;
//import java.util.Scanner;
//
//import static org.junit.jupiter.api.Assertions.*;
//
///**
// * @author - ryan01234keroro56789@gmail.com (Giver)
// */
//class CyclomaticComplexityCalculatorTest {
//    private CyclomaticComplexityCalculator calculator;
//
//    @BeforeEach
//    void setup() {
//        calculator = new CyclomaticComplexityCalculatorImpl();
//    }
//
//    @Test
//    void test() throws IOException {
//        List<String> sourceCodes = new ArrayList<>();
//        String basePath = "testdata/";
//        int total = 0;
//        try {
//            Scanner sc = new Scanner(new File(basePath + "expected_result"));
//            while(sc.hasNext()) {
//                String filename = sc.next();
//                Integer expected = sc.nextInt();
//                String sourceCode = Files.readString(Paths.get(basePath + filename));
//                sourceCodes.add(sourceCode);
//                int score = calculator.calculate(Collections.singletonList(sourceCode)).score;
//                assertEquals(expected, score);
//                total += score;
//            }
//        }
//        catch (IOException err) {
//            throw new RuntimeException(err);
//        }
//        CyclomaticComplexityReport report = calculator.calculate(sourceCodes);
//        assertEquals(total, report.score);
//    }
//}