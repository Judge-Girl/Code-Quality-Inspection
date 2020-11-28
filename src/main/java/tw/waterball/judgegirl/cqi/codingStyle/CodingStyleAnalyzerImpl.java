package tw.waterball.judgegirl.cqi.codingStyle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzerImpl implements CodingStyleAnalyzer {
    @Override
    public CodingStyleAnalyzeReport analyze(String sourceRoot) {
        try {
            String result = callPython(sourceRoot);
            return new CodingStyleAnalyzeReport(result);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String callPython(String sourceRoot) throws InterruptedException, IOException {
        Process pythonProcess = new ProcessBuilder("python3", getPathToPythonEntry(), sourceRoot).start();
        pythonProcess.waitFor();
        return readProcessOutput(pythonProcess);
    }

    private String getPathToPythonEntry() {
        return "./src/main/python/code_style/main.py";
    }

    private String readProcessOutput(Process process) {
        try {
            InputStream stdout = process.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(stdout));

            String totalResult = "", line;
            while ((line = reader.readLine()) != null) {
                totalResult += line;
            }

            return totalResult;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
