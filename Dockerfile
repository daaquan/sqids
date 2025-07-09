FROM php:8.4-cli

# Install build dependencies and prepare the source
RUN apt-get update && apt-get install -y \
    build-essential \
    autoconf \
    libgmp-dev \
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
    && apt-get remove --purge -y autoconf gcc g++ make php-dev linux-headers \
    && apt-get autoremove -y \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

CMD ["php", "-a"]
