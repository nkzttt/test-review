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
docker run --rm -v `pwd`:/work vvakame/review /bin/sh -c "cd /work && review-init myproject"
```

create pdf as test run:

```bash
docker run --rm -v `pwd`/myproject:/work vvakame/review /bin/sh -c "cd /work && review-pdfmaker config.yml"
```

## using starter

if you want to use starter of review you access to [Re:VIEW Starter](https://kauplan.org/reviewstarter/) page.  
when you get a project from the starer you put the project to your project directory.  

the project from the starer need another docker image so install that:

```bash
docker pull kauplan/review2.5
```

create pdf as test run:

```bash
docker run --rm -v `pwd`/starterproject:/work kauplan/review2.5 /bin/sh -c "cd /work && review-pdfmaker config.yml"
```

---

enjoy Re:VIEW!!
