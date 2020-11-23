package tw.waterball.judgegirl.cqi.codingStyle;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.xml.sax.InputSource;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.StringReader;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzeReport {
    public String rawString;
    private Document resultXml;

    public CodingStyleAnalyzeReport(String result) {
        rawString = result;
        resultXml = convertStringToXMLDocument(result);
    }

    public int getScore() {
        Element rootElement = resultXml.getDocumentElement();
        return Integer.parseInt(rootElement.getAttribute("score"));
    }

    private Document convertStringToXMLDocument(String xmlString) {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            return builder.parse(new InputSource(new StringReader(xmlString)));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
