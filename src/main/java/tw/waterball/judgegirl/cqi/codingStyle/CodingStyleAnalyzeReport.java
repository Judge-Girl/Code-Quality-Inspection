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
import org.w3c.dom.Node;
import org.xml.sax.InputSource;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.StringReader;
import java.util.Arrays;
import java.util.List;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzeReport {
    public String rawString;
    private Document resultXml;
    private Element xmlRootElement;

    public CodingStyleAnalyzeReport(String result) {
        rawString = result;
        resultXml = convertStringToXMLDocument(result);
        xmlRootElement = resultXml.getDocumentElement();
    }

    public int getScore() {
        return Integer.parseInt(xmlRootElement.getAttribute("score"));
    }

    public List<String> getBadNamingStyleList() {
        return Arrays.asList(xmlRootElement.getAttribute("bad_naming_style_list").split(","));
    }

    public List<String> getGlobalVariableList() {
        return Arrays.asList(xmlRootElement.getAttribute("global_variable_list").split(","));
    }

    private Document convertStringToXMLDocument(String xmlString) {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            return builder.parse(new InputSource(new StringReader(xmlString)));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
