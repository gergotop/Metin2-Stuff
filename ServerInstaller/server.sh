#!/bin/sh

mkdir server                       && \
cd server                            && \
mkdir tmp && \
cd tmp && \
fetch http://down.serverrent.hu/metin2_server.tar.gz && \
tar -xf metin2_server.tar.gz                                  && \
rm metin2_server.tar.gz
mv * ../