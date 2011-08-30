Geef (Git NIF)
================

Geef is a simple Erlang NIF that exposes some of the libgit2 library functions
to Erlang.

INSTALLING AND RUNNING
========================

First you need to install libgit2:

    $ git clone git://github.com/libgit2/libgit2.git
    $ cd libgit2
    $ make
    $ make install

Now, if you have Erlang OTP_R13B04 installed, you can compile this NIF to run
in it.

    $ git clone git://github.com/schacon/geef.git
    $ cd geef
    $ make

Now you should have a .beam file you can load.  I've also included an example
escript to test some of the functions (currently just hex_to_raw and object_exists):

    $ ./geef h2r de08fe4884650f067bd5703b8a59a8b3b3c99aaa
    Raw: <<222,8,254,72,132,101,15,6,123,213,112,59,138,89,168,179,179,201,154,170>>

    $ ./geef exists .git/objects 89c86150c8b164f441a73f4991b2c339fd4aae7c
    Exists: true

    $ ./geef exists .git/objects 87fcfb277899097823911006f438658ce86b3697
    Exists: false

The API looks basically like this:

    geef:start().
    Raw = geef:hex_to_raw(HexSha).
    Exists = geef:object_exists(ObjectsPath, HexSha).


CONTRIBUTING
==============

Fork schacon/geef on GitHub, make it awesomer (preferably in a branch named
for the topic), send a pull request.


AUTHORS 
==============

Scott Chacon <schacon@gmail.com>


LICENSE
==============

MIT.

