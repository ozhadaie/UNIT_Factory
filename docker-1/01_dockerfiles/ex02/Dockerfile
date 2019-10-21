FROM ruby

RUN apt-get update && apt-get upgrade -y && apt-get install -y build-essential libpq-dev nodejs sqlite3 && gem install --user rails

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
