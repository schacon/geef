-module(geef).
-export([start/0, object_exists/1]).

start() ->
    erlang:load_nif("geef", 0).

object_exists(_Val) ->
    nif_error(?LINE).    

nif_error(Line) ->
    exit({nif_not_loaded,module,?MODULE,line,Line}).
