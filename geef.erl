-module(geef).
-export([start/0, hex_to_raw/1, object_exists/2]).

start() ->
    erlang:load_nif("geef", 0).

hex_to_raw(_Val) ->
    nif_error(?LINE).    

object_exists(_Val, _Val2) ->
    nif_error(?LINE).

nif_error(Line) ->
    exit({nif_not_loaded,module,?MODULE,line,Line}).
