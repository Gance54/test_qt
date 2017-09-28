#!/bin/bash

URL="http://edimka.ru"
CAT_DIR=categories
PROD_DIR=products
CONS_DIR=consumables
read_cons()
{
    (test -n "$1" && test -n "$2" && test -n "$3" && test -n "$4") || return;
    FILE="$CONS_DIR"/"$2"".txt"
    TMP_FILE="$CONS_DIR"/"$2"".tmp"
    test -f "$FILE" && return;
    wget -O "$TMP_FILE" -o /dev/null -U 'Mozilla/5.0' $URL$1 && iconv -f WINDOWS-1251 -t UTF-8 "$TMP_FILE" | grep '<h1>' | \
    sed 's/<a href="[^ ]*" class=at>//g' | sed 's/<h1>[^ ]*<\/h1>//g' | sed 's/<[^ ]*>//g'> "$FILE";
    rm "$TMP_FILE";
}

test -d $CAT_DIR || mkdir $CAT_DIR
test -d $PROD_DIR || mkdir $PROD_DIR
test -d $CONS_DIR && rm -rf $CONS_DIR
mkdir $CONS_DIR

#get categories
wget -O 1.tmp -o /dev/null -U 'Mozilla/5.0' $URL/tables/0-0 && iconv -f WINDOWS-1251 -t UTF-8 1.tmp | \
sed "s/<br/\n<br/g; s/<br \/>/<br>/g" | grep '<a class="bigs"' | sed "s/^.*href='//g; s/'><img src=.*\/>/=/g; s/<\/a>//g" > categories.txt && rm 1.tmp

cat categories.txt | \
while IFS='=' read LINK FNAME; do
    TFNAME=$(echo -e "$FNAME" | sed "s/\//-/g")
    FILE="$CAT_DIR/$TFNAME.txt"
    TMP_FILE="$CAT_DIR/$TFNAME.tmp"
    
    wget -O "$TMP_FILE" -o /dev/null -U 'Mozilla/5.0' $URL$LINK  && iconv -f WINDOWS-1251 -t UTF-8 "$TMP_FILE" | sed "s/<\/td><\/tr>/\n<----->/g;" | 
    grep "<-----><tr" | sed "s/<-----><tr.*href='//g; s/'>/=/g; s/<\/a>.*//g" > "$FILE" && rm "$TMP_FILE"
    cat "$FILE" | \
    while IFS='=' read P_LINK P_NAME; do
        TP_NAME=$(echo -e "$P_NAME" | sed "s/\//-/g")
        FILE="$PROD_DIR/$TP_NAME.txt"
        TMP_FILE="$PROD_DIR/$TP_NAME.tmp"
	echo "$P_NAME..."
        wget -O "$TMP_FILE" -o /dev/null -U 'Mozilla/5.0' $URL$P_LINK && iconv -f WINDOWS-1251 -t UTF-8 "$TMP_FILE" |sed "s/<tr bgcolor=/\n<tr bgcolor=/g" |\
        egrep "<p><b>|^<tr bgcolor=|^<\/span><\/td>" | sed "s/<b>Состав.*border=0>//g" | grep "href=" | sed "s/<p><b><a href='.*'>/cat=/g" |\
        sed "s/<tr bgcolor.*href='//g; s/'>/=/g; s/<\/a><span class=\".*\">//g; s/<\/span><\/td><td align=right>/, /g; s/<\/td><\/tr>//g" |\
        sed 's/<a href="[^ ]*" class=at>//g' | sed "s/<\/a>.*align=justify>/\n/g" | sed "s/<[^ ]*>//g" |\
        sed 's/\(.*\)=\(.*\), \(.*\), \(.*\)/ Requiredpattern|\1|\2|\3|\4/g' | sed "s/<.*>//g" | sed "s/&rarr//g" > "$FILE" && rm "$TMP_FILE"
	cat "$FILE" | grep "Requiredpattern" |\
        while IFS="|" read REQ LINK NAME CUR CNT; do
            read_cons "$LINK" "$NAME" "$CUR" "$CNT"
        done
    done
done
