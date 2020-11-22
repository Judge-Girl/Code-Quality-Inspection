expand_cpp(){
     sed 's|^\([ \t]*#[ \t]*include\)|magic_fjdsa9f8j932j9\1|' "$@" \
    | cpp | sed 's|^magic_fjdsa9f8j932j9||; /^# [0-9]/d' | grep -v '^\([ \t]*#[ \t]*include\)' | tr -d '\n\r\t'
}
code=$(($(expand_cpp < "$1" | grep -o "\([^0-9A-Za-z_]\(\(if\)\|\(case\)\|\(for\)\|\(while\)\|\(catch\)\)[^0-9A-Za-z_]\)\|[&][&]\|[|][|]\|[?]" | wc -l )))
literal=$(($(expand_cpp < "$1" | egrep \"\(\\\.\|[^\"]\)*\" -o | grep -o "\([^0-9A-Za-z_]\(\(if\)\|\(case\)\|\(for\)\|\(while\)\|\(catch\)\)[^0-9A-Za-z_]\)\|[&][&]\|[|][|]\|[?]" | wc -l )))
res=$((code-literal))
echo "$1 $res"
