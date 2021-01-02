FROM adoptopenjdk/openjdk11:alpine-slim
RUN apk add gcc
RUN apk add python3
RUN apk add py3-pip
RUN pip3 install --upgrade pip
RUN apk add python3-dev
RUN apk add musl-dev
RUN pip3 install nltk
RUN apk add cppcheck
RUN python3 -m nltk.downloader words
COPY target/*.jar /app.jar
COPY src/main/python/code_style /code_style

ENTRYPOINT ["java","-cp","/app.jar","tw.waterball.judgegirl.cqi.main.Main"]

