rm ./test/*.out
for file in input/*
do
    basename "$file"
    name="$(basename -- ${file%.*})"
    ./myscanner "./input/$name.c" >> "./test/${name}.out"
    cmp --silent "./output/$name.out" "./test/${name}.out" || echo "files are different"
    # diff "./output/$name.out" "./test/${name}.out" -y -W 100
done