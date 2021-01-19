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

package tw.waterball.judgegirl.cqi.csa;

import java.util.List;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzeReport {
    private int score;
    private String formula;
    private List<String> illegalNamingStyleList, globalVariableList;
    public CodingStyleAnalyzeReport(int score, String formula, List<String> illegalNamingStyleList, List<String> globalVariableList) {
        this.score = score;
        this.formula = formula;
        this.illegalNamingStyleList = illegalNamingStyleList;
        this.globalVariableList = globalVariableList;
    }

    public int getScore() {
        return score;
    }

    public String getFormula() {
       return formula;
    }

    public List<String> getIllegalNamingStyleList() {
        return illegalNamingStyleList;
    }

    public List<String> getGlobalVariableList() {
        return globalVariableList;
    }
}
