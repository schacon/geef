#include "erl_nif.h"
#include <stdio.h>
#include <git/common.h>
#include <git/oid.h>

#define MAXBUFLEN       1024

static ERL_NIF_TERM
geef_hex_to_raw(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
  char sha[MAXBUFLEN];
  (void)memset(&sha, '\0', sizeof(sha));

  if (enif_get_string(env, argv[0], sha, sizeof(sha), ERL_NIF_LATIN1) < 1)
      return enif_make_badarg(env);

  git_oid oid;

  printf("sha: %s\n", sha);
  git_oid_mkstr(&oid, sha);

  ErlNifBinary ibin;
  enif_alloc_binary(env, 20, &ibin);
  memcpy(ibin.data, (&oid)->id, 20);

  return enif_make_binary(env, &ibin);
}

static ErlNifFunc geef_funcs[] =
{
  {"hex_to_raw", 1, geef_hex_to_raw}
};

ERL_NIF_INIT(geef, geef_funcs, NULL, NULL, NULL, NULL)
