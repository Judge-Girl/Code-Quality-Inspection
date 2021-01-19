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
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;
import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author edisonhello edisonhello@hotmail.com
 */

public class CodingStyleAnalyzerImpl implements CodingStyleAnalyzer {

    public CodingStyleAnalyzeReport analyze(String sourceRoot) {
        return analyze(sourceRoot, Collections.emptyList());
    }

    @Override
    public CodingStyleAnalyzeReport analyze(String sourceRoot, List<String> variableWhitelist) {
        try {
            String xmlResult = callPython(sourceRoot, variableWhitelist).trim();
            System.out.println("XML result: " + xmlResult);
            if (xmlResult.isEmpty()) {
                throw new IllegalStateException("XML result should not be empty.");
            } else {
                Document resultXml = convertStringToXMLDocument(xmlResult);
                return buildReportFromXmlRoot(resultXml);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private Node getXmlNodeByXPath(Document xml, String xPath) {
        try {
            XPath xPathInstance = XPathFactory.newInstance().newXPath();
            NodeList nodeList = (NodeList) xPathInstance.compile(xPath).evaluate(xml, XPathConstants.NODESET);
            return nodeList.item(0);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private List<String> retrieveTopLevelResultList(Document xml, String tagName, String attrbuteName) {
        Element element = (Element)getXmlNodeByXPath(xml, "/folder/" + tagName);
        String resultString = element.getAttribute(attrbuteName);
        String[] strings = resultString.split(",");

        if (strings.length == 1 && strings[0].equals("")) {
            return Collections.emptyList();
        } else {
            return Arrays.asList(strings);
        }
    }

    private CodingStyleAnalyzeReport buildReportFromXmlRoot(Document xml) {
        try {
            Element xmlRootElement = xml.getDocumentElement();
            int score = Integer.parseInt(xmlRootElement.getAttribute("score"));
            String formula = xmlRootElement.getAttribute("using_formula");
            List<String> illegalNamingStyleList = retrieveTopLevelResultList(xml, "naming_style", "illegal_naming_style_variable_list");
            List<String> globalVariableList = retrieveTopLevelResultList(xml, "global_variable", "global_variable_list");
            return new CodingStyleAnalyzeReport(score, formula, illegalNamingStyleList, globalVariableList);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String callPython(String sourceRoot, List<String> variableWhitelist) throws InterruptedException, IOException {
        // variable white list expect one argument otherwise ',' stands for no white list
        String variableWhiteList = variableWhitelist.isEmpty() ? "," : String.join(",", variableWhitelist);
        Process pythonProcess = new ProcessBuilder("python3", getPathToPythonEntry(), sourceRoot,
                                                   // "--disable-single-character-word",
                                                    "--variable-whitelist", variableWhiteList
                                                ).start();
        pythonProcess.waitFor();
        return readProcessOutput(pythonProcess);
    }

    private String getPathToPythonEntry() {
        // TODO: a drunk way of injecting the path by env (should be improved)
        String path = System.getenv("csa_python_main_path");
        System.out.printf("Python src root: '%s'.\n", path);
        return path;
    }

    private String readProcessOutput(Process process) {
        try {
            InputStream stdout = process.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(stdout));

            StringBuilder totalResult = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                totalResult.append(line);
            }

            return totalResult.toString();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
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
