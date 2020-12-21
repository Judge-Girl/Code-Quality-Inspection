package tw.waterball.judgegirl.cqi.codingStyle;

import java.util.List;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public interface CodingStyleAnalyzer {
    CodingStyleAnalyzeReport analyze(String sourceRoot);
    CodingStyleAnalyzeReport analyze(String sourceRoot, List<String> variableWhitelist);
}
