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

import java.nio.file.Paths;
import java.util.HashSet;

import static org.junit.jupiter.api.Assertions.*;

class CyclomaticComplexityCalculatorTest {
    private CyclomaticComplexityCalculator calculator;

    @BeforeEach
    void setup() {
        calculator = new CyclomaticComplexityCalculatorImpl();
    }

    @Test
    void test() {
        CyclomaticComplexityReport report = calculator.calculate(
                new HashSet<>()
        );
        assertEquals("Hello World", report.mock);
    }
}