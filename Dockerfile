FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y


EXPOSE 33333

WORKDIR /root/
RUN mkdir exam_01_07_06_2023
WORKDIR /root/exam_01_07_06_2023/
COPY . /root/exam_01_07_06_2023/


RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]