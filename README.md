# protopia4ard
this is library for arduino network programming.
it includes packet analyze, dump function, header define, etc..

## how to create library object
```
cd /path/to/protopia
make # then created shared library object at ./bin
sudo cp ./bin/libprotopia /usr/lib
```

## gcc sample
gcc -o object srcname.c -L/path/to/protopia/bin/protopia.so -lprotopia

