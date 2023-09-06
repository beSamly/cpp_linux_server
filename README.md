# Run Postgres DB docker container
```
docker run -p 5432:5432 --name postgresdb -v /var/lib/postgresql:/var/lib/postgresql/data -e POSTGRES_DB=postgres -e POSTGRES_USER=postgres -e POSTGRES_PASSWORD=postgres -d postgres:14.1
```

Trouble shooting
```
#1
Issue : FATAL: could not open file "global/pg_filenode.map": Permission denied
Solution : sudo chown -R 777 /var/lib/postgresql
Description : Give all permission to all user for the directory given to the container for persisten volume
```


# Install C++ PostgresDB client library
In Ubuntu
```
sudo apt install libpqxx-6.4 libpqxx-dev

# It will install pgxx.h in /usr/include
# Verify ls /usr/include |grep pqxx

# It will install libpqxx file somewhere /usr/lib/**(depending on linux system)
# Add -lpqxx option when compiling executable file
```
In Redhat
```
Need to update
```

# Run Oracle DB 21 container
```
docker run -d -p 5500:5500 --name OracleDB container-registry.oracle.com/database/enterprise:21.3.0.0
```


# Install pulsar
```
sudo apt install apache-pulsar-client apache-pulsar-client-dev
```
# Run apache-pulsar docker container
```
docker run -d -p 6650:6650 -p 8080:8080 --name pulsar apachepulsar/pulsar:3.1.0 bin/pulsar standalone
```