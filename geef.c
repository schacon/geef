#include "erl_nif.h"
#include <stdio.h>
#include <git/common.h>
#include <git/oid.h>


static int
load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
    return 0;
}

static int
reload(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
    return 0;
}

static int
upgrade(ErlNifEnv* env, void** priv, void** old_priv,
          ERL_NIF_TERM load_info)
{
    return 0;
}

static void
unload(ErlNifEnv* env, void* priv)
{
    return;
}

static ERL_NIF_TERM
object_exists(ErlNifEnv* env, ERL_NIF_TERM a1)
{
  git_oid oid;
  static char *sha = "ce08fe4884650f067bd5703b6a59a8b3b3c99a09";
  printf("sha: %s\n", sha);
  git_oid_mkstr(&oid, sha);
  //printf("raw: %s", (&oid)->id);

    unsigned long val;
    if(!enif_get_ulong(env, a1, &val)) {
        return enif_make_badarg(env);
    } else {
        return enif_make_ulong(env, val*2);
    }
}

static ErlNifFunc geef_funcs[] =
{
    {"object_exists", 1, object_exists}
};

ERL_NIF_INIT(geef, geef_funcs, load, reload, upgrade, unload)
