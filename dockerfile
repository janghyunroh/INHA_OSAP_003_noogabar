FROM ubuntu:18.04

RUN apt update
RUN apt install -y gcc

RUN mkdir /noogabar
ADD src ./src
ADD mainApp ./

CMD [ "./mainApp" ]