# Re:VIEW test

on Mac OSX.  

## create environment with docker

install docker and docker-machine if you don't install yet:

```bash
brew install docker docker-machine
```

create machine:  
※ required [VirtualBox](https://www.virtualbox.org/)  

```bash
docker-machine create --driver virtualbox default
```

install image:  
※ reference [repository](https://github.com/vvakame/docker-review)  

```bash
docker pull vvakame/review
```

## create Re:VIEW project

move project directory:

```bash
cd mydirectory
```

Initialize project:

```bash
docker run --rm -v `pwd`:/work vvakame/review:3.0 /bin/sh -c "cd /work && review-init myproject"
```

create pdf as test run:

```
docker run --rm -v `pwd`/myproject:/work vvakame/review:3.0 /bin/sh -c "cd /work && review-pdfmaker config.yml"
```
