package tw.waterball.judgegirl.cqi.main;

import tw.waterball.judgegirl.cqi.codingStyle.CodingStyleAnalyzeReport;
import tw.waterball.judgegirl.cqi.codingStyle.CodingStyleAnalyzer;
import tw.waterball.judgegirl.cqi.codingStyle.CodingStyleAnalyzerImpl;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityCalculatorImpl;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityCalculator;
import tw.waterball.judgegirl.cqi.cyclomatic.CyclomaticComplexityReport;


import java.io.File;
import java.nio.file.Path;
import java.util.List;
import java.util.ArrayList;

public class Main{

    public static void main(String[] args){
        if(args.length!=1){
            System.out.println("Expected one argument: sourceRootPathString.");
            return;
        }
        String sourceRootPathString = args[0];
        Path sourceRootPath = Path.of(sourceRootPathString);
        File folder = sourceRootPath.toFile();
        File[] fileList = folder.listFiles();
        List<String> sourceCodes = new ArrayList<>();
        for(int i = 0; i < fileList.length; i++) {
            sourceCodes.add(fileList[i].getPath());
        }
        CyclomaticComplexityCalculator calculator = new CyclomaticComplexityCalculatorImpl();
        CyclomaticComplexityReport ccReport = calculator.calculate(sourceCodes);
        CodingStyleAnalyzer analyzer = new CodingStyleAnalyzerImpl();
        CodingStyleAnalyzeReport csaReport = analyzer.analyze(sourceRootPathString);
        System.out.println(ccReport.score);
        System.out.println(csaReport.getScore());
    }
}
