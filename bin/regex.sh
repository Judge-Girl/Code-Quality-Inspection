#
# Copyright 2020 Johnny850807 (Waterball) 潘冠辰
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#       http://www.apache.org/licenses/LICENSE-2.0
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#

expand_cpp(){
     sed 's|^\([ \t]*#[ \t]*include\)|magic_fjdsa9f8j932j9\1|' "$@" \
    | cpp | sed 's|^magic_fjdsa9f8j932j9||; /^# [0-9]/d' | grep -v '^\([ \t]*#[ \t]*include\)' | tr -d '\n\r\t'
}
code=$(($(expand_cpp < "$1" | grep -o "\([^0-9A-Za-z_]\(\(if\)\|\(case\)\|\(for\)\|\(while\)\|\(catch\)\)[^0-9A-Za-z_]\)\|[&][&]\|[|][|]\|[?]" | wc -l )))
literal=$(($(expand_cpp < "$1" | egrep \"\(\\\.\|[^\"]\)*\" -o | grep -o "\([^0-9A-Za-z_]\(\(if\)\|\(case\)\|\(for\)\|\(while\)\|\(catch\)\)[^0-9A-Za-z_]\)\|[&][&]\|[|][|]\|[?]" | wc -l )))
result=$((code-literal))
echo "$1 $result"
