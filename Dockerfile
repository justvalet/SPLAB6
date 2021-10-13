FROM ubuntu
RUN apt update
RUN apt install g++ -y
COPY dsnm-6.cpp  . 
COPY dsnunm-6.cpp  . 