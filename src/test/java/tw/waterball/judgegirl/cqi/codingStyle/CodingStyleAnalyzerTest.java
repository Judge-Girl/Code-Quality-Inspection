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