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

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import java.util.Arrays;
import java.util.List;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzeReport {
    private int score;
    private List<String> badNamingStyleList, globalVariableList;
    public CodingStyleAnalyzeReport(int score, List<String> badNamingStyleList, List<String> globalVariableList) {
        this.score = score;
        this.badNamingStyleList = badNamingStyleList;
        this.globalVariableList = globalVariableList;
    }

    public int getScore() {
        return score;
    }

    public List<String> getBadNamingStyleList() {
        return badNamingStyleList;
    }

    public List<String> getGlobalVariableList() {
        return globalVariableList;
    }
}
