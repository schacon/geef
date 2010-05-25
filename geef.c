#include "erl_nif.h"
#include <stdio.h>
#include <git/common.h>
#include <git/oid.h>
#include <git/odb.h>

#define MAXBUFLEN       1024

static ERL_NIF_TERM
geef_hex_to_raw(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
  char sha[MAXBUFLEN];
  (void)memset(&sha, '\0', sizeof(sha));

  if (enif_get_string(env, argv[0], sha, sizeof(sha), ERL_NIF_LATIN1) < 1)
      return enif_make_badarg(env);

  git_oid oid;
  git_oid_mkstr(&oid, sha);

  ErlNifBinary ibin;
  enif_alloc_binary(env, 20, &ibin);
  memcpy(ibin.data, (&oid)->id, 20);

  return enif_make_binary(env, &ibin);
}

static ERL_NIF_TERM
geef_object_exists(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
  char path[MAXBUFLEN];
  char sha[MAXBUFLEN];
  (void)memset(&path, '\0', sizeof(path));
  (void)memset(&sha, '\0', sizeof(sha));

  if (enif_get_string(env, argv[0], path, sizeof(path), ERL_NIF_LATIN1) < 1)
      return enif_make_badarg(env);
  if (enif_get_string(env, argv[1], sha, sizeof(sha), ERL_NIF_LATIN1) < 1)
      return enif_make_badarg(env);

  git_odb *odb;
  git_odb_open(&odb, path);

  git_oid oid;
  git_oid_mkstr(&oid, sha);

  int exists = git_odb_exists(odb, &oid);
  if(exists == 1) {
    return enif_make_atom(env, "true");
  }
  return enif_make_atom(env, "false");
}

static ErlNifFunc geef_funcs[] =
{
  {"hex_to_raw", 1, geef_hex_to_raw},
  {"object_exists", 2, geef_object_exists}
};

ERL_NIF_INIT(geef, geef_funcs, NULL, NULL, NULL, NULL)
