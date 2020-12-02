package tw.waterball.judgegirl.cqi.codingStyle;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

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
        assertEquals(0, report.getScore());
    }

    @Test
    void testGlobalVariableCount() {
        CodingStyleAnalyzeReport report = analyzer.analyze("./testdata/codes/globalvar");
        assertEquals(-6, report.getScore());
    }
}