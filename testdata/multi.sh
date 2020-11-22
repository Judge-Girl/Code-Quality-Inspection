tot=$((0))
for file in "$@"
do
    bash regex.sh "$file"
done
