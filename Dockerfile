FROM php:8.3-cli-alpine

# Install build dependencies and prepare the source
RUN apk add --no-cache --virtual .build-deps \
        autoconf gcc g++ make php8-dev linux-headers gmp-dev \
    && docker-php-source extract

# Copy extension sources
COPY ./ext /usr/src/php/ext/sqids

# Build and install the extension
RUN cd /usr/src/php/ext/sqids \
    && phpize \
    && ./configure --enable-sqids \
    && make -j$(nproc) \
    && make install

# Enable the extension
COPY ./php.ini /usr/local/etc/php/conf.d/sqids.ini

# Cleanup build dependencies
RUN docker-php-source delete \
    && apk del .build-deps

CMD ["php", "-a"]
