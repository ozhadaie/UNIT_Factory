FROM debian

RUN apt-get update && apt-get install -y fortune cowsay lolcat

ENTRYPOINT /usr/games/fortune | /usr/games/cowsay | /usr/games/lolcat
