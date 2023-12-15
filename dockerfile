FROM ubuntu:18.04

RUN apt update
RUN apt install -y gcc

RUN mkdir /noogabar
ADD AVLTreeSet ./AVLTreeSet
ADD header ./header
ADD Main ./Main
ADD Tests ./Tests

