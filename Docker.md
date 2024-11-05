# Docker commands:

## Docker:
 |Commands                                 | To do                                      |
| ----------------------------------------- | ------------------------------------------------- |
|docker build -t <image's name>:<version> .| Build dockers images. Best att use ex: customer: lastest'for the images name and version  |
|docker images | Show all images|
|docker run -d --name <containers name> -p <ports> <image's name>:<version> | run the docker image|

## Docker compose commands:

|Commands                                 | To do                                      |
| ----------------------------------------- | ------------------------------------------------- |
|docker-compose up|run docker compose file to run all applications in this file. Need to cd to the folder that contains docker-compose file. |
|docker rmi -f customer:latest kitchen:latest && docker-compose up| run docker compose file if you have build and used images before|

