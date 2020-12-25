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

package tw.waterball.judgegirl.cqi.codingStyle;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class CodingStyleAnalyzerTest {
    private CodingStyleAnalyzer analyzer;

    @BeforeEach
    void setup() {
        analyzer = new CodingStyleAnalyzerImpl();
    }

    @Test
    void test() {
        CodingStyleAnalyzeReport report = analyzer.analyze("./testdata/codes/teamcode");
        assertEquals(-127, report.getScore());
    }

    @Test
    void testGlobalVariableCount() {
        CodingStyleAnalyzeReport report = analyzer.analyze("./testdata/codes/globalvar");
        assertEquals(-18, report.getScore());
    }

    @Test
    void testBadNamingStyleCount() {
        CodingStyleAnalyzeReport report = analyzer.analyze("./testdata/codes/namingstyle");
        assertEquals(-38, report.getScore());
    }

    @Test
    void testWhitelist() {
        List<String> whitelist = Arrays.asList("i", "j", "k");
        CodingStyleAnalyzeReport report = analyzer.analyze("./testdata/codes/whitelist", whitelist);
        assertEquals(-23, report.getScore());
    }
}