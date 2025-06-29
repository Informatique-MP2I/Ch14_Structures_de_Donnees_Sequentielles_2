open Yojson.Safe.Util
type character = {
  name : string;
  age  : int;
  hero : bool
}
(* JSON format deserialization function of a character *)
let deserialize_character json =
  { name = to_string (member "name" json);
    age =  to_int (member "age" json);
    hero = to_bool (member "hero" json) }
(* JSON format deserialization function of a list of characters *)
let deserialize_characters json =
  let json_list = to_list (Yojson.Safe.from_string json) in
  List.map deserialize_character json_list
let () =
  let ic = open_in "characterOCaml.json" in
  let json_string = really_input_string ic (in_channel_length ic) in
  close_in ic;
  let characters = deserialize_characters json_string in
  List.iter (fun c -> Printf.printf
    "Name: %s\nAge: %d\nHero: %B\n\n" c.name c.age c.hero) characters
