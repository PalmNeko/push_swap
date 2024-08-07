
![push_swap](https://github.com/PalmNeko/push_swap/assets/54460913/aba17b3a-2b26-4c13-81ad-486aecc2eff4)

# PUSH_SWAP

プッシュスワッププロジェクト

# アルゴリズム

[turksort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)を使ってソートした。
一部工夫した。

* turksort概要
 基本的に片方のスタックからソート済みのスタックにプッシュする。
 プッシュする際に、ソートされている状態を崩さないようにプッシュする。
 プッシュする際に、未ソートのスタックのうちどれをプッシュすると一番コストが低くなるかを計算する。
* 工夫した点
 元のアルゴリズムは、スタックA -> スタックB -> スタックAという流れでソートする。
 一旦スタックBに対して、閾値を設けて5分割されるようにプッシュし、スタックAに対してturksortを実行した。
*

#
v0.1 : [text](https://patrick-hacks.github.io/push-swap-pain/?&nbr=271,200,33,119,13,236,143,196,383,371,89,134,7,405,297,94,187,442,396,228,477,103,215,28,284,362,67,207,323,493,256,174,355,384,51,345,2,24,407,441,344,34,327,332,482,114,462,178,122,136,60,204,280,175,432,181,41,392,416,252,123,137,351,287,190,317,395,231,44,352,213,406,92,195,460,164,365,193,176,445,459,350,201,127,165,425,156,483,38,163,98,402,492,78,82,444,95,208,14,265,288,86,372,186,375,429,177,69,294,269,356,456,289,52,360,4,366,413,359,453,131,399,417,48,93,455,298,115,463,5,380,202,423,304,338,367,226,343,171,87,276,197,56,191,449,71,222,80,251,73,206,490,75,478,335,398,39,361,330,491,21,36,440,414,29,354,227,70,221,61,81,110,272,329,59,214,230,278,9,428,182,209,364,385,285,250,245,266,125,379,118,427,410,486,300,172,306,485,129,126,496,261,302,270,290,305,106,451,337,333,158,135,415,147,185,295,353,275,12,340,255,107,309,292,390,43,152,279,378,349,212,319,35,470,377,342,426,167,430,55,409,229,45,218,240,388,454,232,162,146,400,46,25,216,438,404,334,286,268,144,84,386,262,239,347,57,420,394,241,53,3,291,321,247,336,23,389,471,273,217,339,18,494,318,328,111,138,257,324,76,50,179,102,325,54,188,357,0,468,223,310,32,457,253,153,19,198,299,258,189,458,238,121,263,244,192,393,10,62,373,100,210,277,452,203,145,169,139,170,148,211,242,133,49,63,466,341,79,487,368,132,474,381,130,461,322,22,15,168,473,411,108,159,450,96,489,30,264,166,116,249,26,443,233,408,475,293,412,387,149,254,235,465,161,31,439,219,120,320,498,151,128,246,104,495,97,155,313,66,68,260,224,243,326,374,173,109,363,424,348,88,237,142,99,436,150,101,20,194,225,283,16,435,296,248,199,484,64,65,112,42,183,74,464,418,83,140,446,358,447,6,113,433,85,421,422,467,90,401,124,301,154,480,499,184,370,77,316,17,141,314,469,472,117,8,346,391,331,259,37,481,311,274,369,497,448,431,437,160,234,479,308,476,488,205,91,105,267,220,40,397,403,312,58,11,281,27,315,157,72,382,1,434,307,47,180,282,419,376,303&cmd=kkekkeekeekeekkhhhkekegkikikhhkhkigkhhhhkddkihhhkikhhhkeegkfeeekddkhhddkhhddkiiggkhhhhhhkgkhhhkhhkfkdddkfdkfdddkfkkhhhhhhhhhhhkfekeegggkeegkeeggggkgggggkiiikihhhhkfddkhdddkhhkhhkikhhhhkhdkhkikegkdddkhhdkiigkgggkhhhkhdkfffdkhhhhhdddkhhdkiihhhkddddkhhddddddkffffekhhhhhhhhhhhhhdddkhhhhhhdkddddkffeeekeeeeeeeegggkfffffdddkdkhhhhhhhhhkhhhhdddddkfddddddkdddddkhhddkhhhhhhhkiiiihhhkhhhkhhhdkiiggkhhhhhhhhhhddddkhhhddddkhhhhhdddkffffdddkeeeeggkffekeeeeegggggkigkeeeeeeeeggkeeeeeeeeeeeeekeekhdkkekdkfffeeeeekfdddkffekeeegggkeeeeeeeegkeggggggkeeekeeeeeeegkffffkeeeeekeeeegggkeeeeeeeeeekfekeeeeeeegkikgkeggkeeeeeeegkeegggkeegggggggggkgggkeegggggkeeeeeeegkddddkeeeeeeeeeeggggggkffeeeeeeekeeeekeeeegggggggkeggkikeeeeeeegkfeeeeekfdkfeeeekeggkeegkfeeekfeekeeeeegggkeeeeeeeekffeekeeeeeeeeeeeeeggggkgggggkfffeeekffffeeeeeekhddkhdkeeeeeeeeggkeeeeekeeeeekeggkeeeekgkeegkfffffffeeeeeekeeeeeeeeeeeeeeeegkhdddkhhhddddddkffeeeeeeekeeeeegkgkeeeeeeegggkgggggkhhhhkeeeegggggkiikiiggggggggkfeeeeeeeekffeeeeeeeekfkhhhhdkeeeeeeeeeeeegkeeeeegkeeeeggggggkeeeeegkfffffdddkhhddddddddkiihkhddddddddkeekffffffeeekddddddddddddddkhhhhhhhhhhhhhhhhddddkeggggggggggggkiigkeeeeeeekhhhhhhhhhhhhhhhhhhdkeeeeeeeegggggggggggggkiiiiiiigkiigggggggggkeggggggkeeeeeeeeeeeeeeeeeggggkigggggggggggggggggggkeeeeeeegggggggggggggggggggkiiigggggkeeeeeeeeeeeeeeggkeeeeeeeggggggggkfeeeeeeeeeeekhhhdddkffffffeekiiigggggggggggggkeeeeeegggkeeeeeggggkegkfeeeeekeeeeeeeeeegggggggkggggkfffffffeeeeeekffeeekdddddddddkhhddkhhhhhhhkiiiiggkhhhhddddddddkffffkhhhhhhhhhhhhddddkhhddddddddddddddddddkhhhhhhdddkdddddddkiiihhkffddddddddkeeeeekfekeeeeeeeggggkeeggggkeeeeeeeeeegggggkeeeeeeeeggkfddddddddddkffffffeeeeeeekfdkhhhhhkhhhhhhhhhhddddddddddddkhhhhhhhhhhhhdddddddddddkiiiiiihkhddddddddddddddkiiihkfffffdddddkeeeeeeeeeeeeeeeeekffddddddddddddddddddddkfffddkeeeeeeeeeeeeeeeeekiiiiggggggkfffffeeeeeeeeeeeeekfdddddddddddddddddkfffeeeekdddddddkfffffdddddddkhhhhhhhhhhdddddddddddkhhhdddddkfddddddkeeeeeeeegggggkfffffffeekffffddddkfeeeeeeeeeeekddkeeeeeeeekiiiiiiigggggggkeeeeeeeeeeeggggggkeeeeeeggkeeeeeeeeeeeeeeeeegggkffffeeeekfffffffddddddddkhhhhhhdddddddddkffddddddkhhhhdddddkhhhhhhhhhhdddddkiihhhhhhhhkiiihhhkhhhhhhhhhhhhhhhhhhhhhddkhhhddddkfddddkfffffeekhdddddkkihhhkihhhhhhhhkeggkhdddddddddddddddddddkfeeeeeeeekeeeeegkdddddddddddddddddkfffdddkfddkeeeeeeeeeeeeekeeeggggggkeeeeeegkeggkffddkeeeeekiiggggkiiiiihhkhhhkhhhhhhhhhddddkfddddddddddddkfffffffeeeeeeeeeeekfeeeeeeeekfdddkhhhhhhhhhddddddddkhhhhhhhddddkhhddkiiiiggggggkiiihhhhhhhhhhhhkhhhdkhhhhhhhddddddddkiiiiihhhhhhhhkiiiiiihhhhhhhkeeeeeeeeeeeeeeeeeggggggggggggggkiiiiiiiiiiiiiiiiiiiigkiikhhhhhhdkiiihhhkeeeeeeeeeeeeeggggkeeeeeeeeggggggkeeegkeeeegggggggggggggggggggggggggggggggggggggggggggkiiiihhhhhkiiiiiiiihhhhkeegggggggggkhhhhhhhhhhhhhhhhhhhhhhhdddkihhhhkhhhhhhddddkffffkhhhhdddddkfffeeeeeeeeeeeeeeeeeeeeeeeeeeekfffdkiiiiiiiiiiiiigggggggggggggggggggggggggggkiiiiiiiigggkiiihhhhhhhhhkiiiiiihhhhhhhhhhhhkeeeggggkiiggggggggggggggkiiigkiiiiihhhhhhhhhhhhhhkffffffdddddddddddddddkhhhhhhhhhhhhhhhdkiiiigkhhhhhhhhhhhhhhhhhkhhhhddddddddddkfffdddddddddddddkfeekhhhhdkihhhhhhhhhkegkfdddddddkfdddkeeeeegggkhddddddddkfffeeeeeekhhhddddkeeeeeggggggggggkfffffeeeeeeeeekeeeeeeegkeeegggggggkeeeeeegggkeeeeeekdddddddddkihhkhhhddddddkfffeeeekdkeeeeeeeeeeggggkeeeeeeeeeeeeeeeeeegggggkeegkeeeggggggggggggkeggggggggggkffffffffeeeeekhhhhhhhhhhhhhhhhhhhhhhhhhhhhhkiiiiiiihhhhhhhhhhkiiiiiihhhhhhhhhhhkhhhhhhhhhddddddddddkekeekhhhhhhhhhhdddddddddddddkhhhhhkffffffffkeeeeeeeeeeeeeeeeeeeeeeeeeeeggkhhhhddddddddkfffffffffffekeeeeeeeeeeeeegkddddddkeeeeeeeeeeekhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddddddddddddddddddddddddddddkffddkiiiiihhhhhhhhhhhhkiiiigkiiihhhhhhhhhhhhhhhhhhhhhhhhhhhkhhhdddkfdkihhhhhhhkikfddddkhdddkhddkiiiiggkiikihhhhhhhhkhhhddddkhhhhhhhhhkffdddkhhhhhhkfeekdkiiihhhhhkeeggggkeegggggkiihhhkhhhddkigggkiiiggggkfeeeeeeeeeeekeeeggggkeeeekeeeeeeeeeeeeeeeegkdddkhhhddkeeeeeeeeeeeeggkiigkiigkegggkhhhhkggkihkeeggkeeggggkigggkiigggkikhhhhhhhhhhhhhhddkiihhhhhhhhhhhhkiiiiihhhhhkhhhhhhhhhdddkfddkfffffkfffffffdddddddddkhhhhhhhhhhhhhhhdddddddddddddkihhhhhhhhhhhhhhhkgggggggggggggggggggkeeeekeeeggkiiiigggggggggggkiiihhhhhhkhhhhhhhhhhhhhhhhhhddddddddddddddddkhhhhhhhhhhhhhhhhhhdddddddddddddddddddddddddddkiiiiiiiiiiiiiiiiiiiiiihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhkiihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhkhhhhhhkddddddkhhdddkhhhhhhhddkhhhhhkeggkhhhhhhhdddddddkhhddkddddkiihhhhhkiihkigkhhhhhkeeggkeeeeggkfdddddkhhhhhhddddkhhhhdddkhhdddkhhdkhhdkfeeekgggggggggkhhhhhdddkhhhhhhhdkiiiiiihhkeeeegggkeeeeeeeeeeeeegkeeeeeegggggggkfeeeeeeeeeeeekegggkeeeeggkeeegggkiigkeegggkihhhhkfffffffeeeeeeeeeekeekeeeegkeeekkfddddkffeeekfeeeeekeeeggkeeekeeeeeeeeeeeegkfeeeeekdddkeeeeegkeeeeeeeeeekkeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeedajjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjgjjjjjjjjjjgjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjgjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj)
 -- 5492
v1.0 : [text](https://patrick-hacks.github.io/push-swap-pain/?&nbr=271,200,33,119,13,236,143,196,383,371,89,134,7,405,297,94,187,442,396,228,477,103,215,28,284,362,67,207,323,493,256,174,355,384,51,345,2,24,407,441,344,34,327,332,482,114,462,178,122,136,60,204,280,175,432,181,41,392,416,252,123,137,351,287,190,317,395,231,44,352,213,406,92,195,460,164,365,193,176,445,459,350,201,127,165,425,156,483,38,163,98,402,492,78,82,444,95,208,14,265,288,86,372,186,375,429,177,69,294,269,356,456,289,52,360,4,366,413,359,453,131,399,417,48,93,455,298,115,463,5,380,202,423,304,338,367,226,343,171,87,276,197,56,191,449,71,222,80,251,73,206,490,75,478,335,398,39,361,330,491,21,36,440,414,29,354,227,70,221,61,81,110,272,329,59,214,230,278,9,428,182,209,364,385,285,250,245,266,125,379,118,427,410,486,300,172,306,485,129,126,496,261,302,270,290,305,106,451,337,333,158,135,415,147,185,295,353,275,12,340,255,107,309,292,390,43,152,279,378,349,212,319,35,470,377,342,426,167,430,55,409,229,45,218,240,388,454,232,162,146,400,46,25,216,438,404,334,286,268,144,84,386,262,239,347,57,420,394,241,53,3,291,321,247,336,23,389,471,273,217,339,18,494,318,328,111,138,257,324,76,50,179,102,325,54,188,357,0,468,223,310,32,457,253,153,19,198,299,258,189,458,238,121,263,244,192,393,10,62,373,100,210,277,452,203,145,169,139,170,148,211,242,133,49,63,466,341,79,487,368,132,474,381,130,461,322,22,15,168,473,411,108,159,450,96,489,30,264,166,116,249,26,443,233,408,475,293,412,387,149,254,235,465,161,31,439,219,120,320,498,151,128,246,104,495,97,155,313,66,68,260,224,243,326,374,173,109,363,424,348,88,237,142,99,436,150,101,20,194,225,283,16,435,296,248,199,484,64,65,112,42,183,74,464,418,83,140,446,358,447,6,113,433,85,421,422,467,90,401,124,301,154,480,499,184,370,77,316,17,141,314,469,472,117,8,346,391,331,259,37,481,311,274,369,497,448,431,437,160,234,479,308,476,488,205,91,105,267,220,40,397,403,312,58,11,281,27,315,157,72,382,1,434,307,47,180,282,419,376,303&cmd=ddkkekdkekfdkkekddkkfdddkfkddkddddkfdkdkkdddkdddkfkekekekddkfkekdddkekfdkfddkdddkkfkfkekfdddkekfkfkkekddkkdkdkddkdkfdkekdddddkdkddddkfdkkddkfkddddddddkekdkekkfkdkdkddkdddkdddkkddkddkdkkkfdkdddkdkfddddddkfkfdddkfdkekfdddddkfddkekfkekfddkddkfddkkfddddkddddkfkddkdddddkekfkkddddddkekddddkdddkkddddkdddddkdddkekfdkkkekfkkfkdddkddkekkfdkfdkfdkfkkdkddddkekekekekfdkekkddkddkfdkfdkkkfdkekfkdkdkekfkdddddddkfddkekddkfdkekfkfkkfkkdddddkekfddkdkekdkekekkfdkdddkfkkkekkekddkkfddkkfkdddkdkfkfdkfkdkkfddkekddddkddddddddkfdddddkkfdkdddkkdkdkekdkddkkfdddkkkkekfkdkekdkkkekkfkkekekfdkekekfdkkdkfkkekkekekkekddkfdkekdddddkkkkekfkkkfkkekfkfkfdkdkekdkekekekkekdkkkddkekekekfddkekkkkekkkdkkekekkkkkfddkkfdkkekkkfkekfkkekkekkekkekkekekkfkekfddkkkkfkdkddkekkkekkkfkekkkekkekfkkkfkekekkekekfkkfkkkdkkkkekekkdkkkdkfkfkfkfdddkkdkddkdkekkddkkfkdkekkkkekekfkekdkkdkkddddkfdddddkfdkekekfdkekekekdkekkfdddkdkfdkkkkfkekkekfkekdkekekkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkjjdjjjdjgjgjdddjfejjeeejggggjjigjijhddjijhddjfffdjffffjffddjddjiiijhjffffejfdjfejffjggjdjjddddddjfdjhhhddjhjddddddjddjhhjffffjfddjfeejeeeejfejfffffdjeeggggjeggjeeeegggjffeeejfeeeejeeegjiiiggggjiigjegggjiiggggggggjihhjhhjgggggjeegjdjigggggjihjhhhhdjhhhhhhhhhhjhjhhhhhhjhddddjfffffdddjfffdddjfddjjddjgggggggjiiiiihhhhhhjffdddddddddjhhdddjfffffffddjhhhhhhhddddddjffffdddjffdddjhddddjhjhdjigggjhjiiiiiiggjiiiiigggggjigggggggggggggggjhdjiggggggggggggjeeeeeeggggggggggggjeegggjiiijigjgggjiigggjijfjiigggggggggjddddddddddddddddddddddddddddjigggggggggggjhdjhjhddjijhjhhjhhdjdddjhjhhdjigjhddjhddddjihjhjhddjhdddjfddjdjihhhhjihjiihjeggjigggjgjjfdjiggggjiijegggjhhhdddddddddddddjhjiijddddddjhddjhhjfddddjihhhjiiggjhhddddjhhhddddjiiiigjiigjhdddjiiiihhhjhhdjhhhddddjhhhdddjfddddjffdddjddddjijhhdddjiiihjhhdjiggjihhjhhdjhhhjiiiigjhdjhhdddddddddjffffffdddjfejhhdddddjdddjfdjffdjgggjfffffdjeeejgjffdjdddjhhdjhhhhhhhhhddjhhdjigjiijiiiggggjhhhhhjgggggggggjeggggggggjffffffffffdddddjejiiiggggggggggggggggggggjiiiiiiggggggggggggggjigggjiggjgggjffeeejddjiggggggggggjigjijhdddjijeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeegggjhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddjggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggjjjdjgjddjfjjeegjddjdjfejffjeejdddjffejeeggjegjegjfdjiiiigjgjegggjgjhhjijhdddjhhdddddjiiijhhdddjfdddjfddjffddjeggggjjfeeeejigggggjejiggggjgjhdjfffffffffeeeeejeeegjiggjfejfdddjffffeeeeeejeeeeeeeeggjfdddddddjiiggggggggggggggggggjiigjihjeeegjhhhhhhhhdjhdddddjddddjiiiiiiigjhhhddddjhhhhdddjfddddjfddddddddddddddddddddddddddddddddddjhhhhjigggjfffffffeeeejfddjffdddddjhddddjhjigjiigjhhhddjhhhddjhjiiijiggjiiiihjhhhhhddddddjihhhhjffffddddjfffdjeeggjfdddddjfddddjdjgjjhhjiiiijiiigjhhhhhdjfddddddddjfffjddddjejhhdjdddjddjhdjiijggjiggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggjhjhjhddjijhdjhhdjijijhhhjihhjhhhddjihhjfffffffjddddddjhjhddjhjiiijigjgjdjiggjihjihhjiiijhhdddddddddjhdjhdjfffdjfdjiihhhjiigjiiiigjiiiiihhhjeeggggjhhhhhhhhdddjhhhhhjhhhhhhhddddjffddddjffddjhddjiijiiiiigjhddddddddddddjfffeeejdddddjeeeejjggggjffffffjfffdddddddjddjjhddjhdjhjhddddddjhjhhhjiggjiiggjgjiiijegggjdjhhhhhhhhhhdddjdddddddjhdjhhhhjfffffddjfeejhddddjdddjhdddjdddjhjiigggjggggggjhhjhhhhhhhjdddddjiihjiigjfffffddddddddddjfddjhddjiiiiiiijhhdddddddddjigggggggggggggggggggggggggggggggggggggggggggggggggggjggggggjffejfjgggggggggjiggjhjiihjeggggjigggggggggjggjjfjjfdjejggjddjdddddjdjjejgjgjddjjhhhjhdddjfffffjffjeeejffeeejiiigggjgggggjgjddjeeeegjjfeeejddjeeeejfffejfjdddddjfffejgjegjeeeeeeegjffffddddjhddjffdddjhhhdjdddjiiggggjhhhhhhdjfdddjiiigggggjhhhhhdjhhhhhhhhdddjiiiigggjiiiiiiihhhjhdjhhhhhhhhhhhhjiiiiigjiiiiigjiijiiijigjhddjhjiigjgjegjjddddddjfffejffjffeejeeeeejejiggjegjegjeejddddjfdjiiiiiggjgggjiihhjhhhhdjiiijfffdddddddjfddjddddjfdddddddddddjffeejffdjfddjhddjhhjhddjhdjffdddjfffffejgggggggggggggggggggggjigggggggggggggggggggggggggggggjigjfddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddjddjfddjdddddjggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg)
 -- 4239
v1.1 : [text](https://patrick-hacks.github.io/push-swap-pain/?&nbr=271,200,33,119,13,236,143,196,383,371,89,134,7,405,297,94,187,442,396,228,477,103,215,28,284,362,67,207,323,493,256,174,355,384,51,345,2,24,407,441,344,34,327,332,482,114,462,178,122,136,60,204,280,175,432,181,41,392,416,252,123,137,351,287,190,317,395,231,44,352,213,406,92,195,460,164,365,193,176,445,459,350,201,127,165,425,156,483,38,163,98,402,492,78,82,444,95,208,14,265,288,86,372,186,375,429,177,69,294,269,356,456,289,52,360,4,366,413,359,453,131,399,417,48,93,455,298,115,463,5,380,202,423,304,338,367,226,343,171,87,276,197,56,191,449,71,222,80,251,73,206,490,75,478,335,398,39,361,330,491,21,36,440,414,29,354,227,70,221,61,81,110,272,329,59,214,230,278,9,428,182,209,364,385,285,250,245,266,125,379,118,427,410,486,300,172,306,485,129,126,496,261,302,270,290,305,106,451,337,333,158,135,415,147,185,295,353,275,12,340,255,107,309,292,390,43,152,279,378,349,212,319,35,470,377,342,426,167,430,55,409,229,45,218,240,388,454,232,162,146,400,46,25,216,438,404,334,286,268,144,84,386,262,239,347,57,420,394,241,53,3,291,321,247,336,23,389,471,273,217,339,18,494,318,328,111,138,257,324,76,50,179,102,325,54,188,357,0,468,223,310,32,457,253,153,19,198,299,258,189,458,238,121,263,244,192,393,10,62,373,100,210,277,452,203,145,169,139,170,148,211,242,133,49,63,466,341,79,487,368,132,474,381,130,461,322,22,15,168,473,411,108,159,450,96,489,30,264,166,116,249,26,443,233,408,475,293,412,387,149,254,235,465,161,31,439,219,120,320,498,151,128,246,104,495,97,155,313,66,68,260,224,243,326,374,173,109,363,424,348,88,237,142,99,436,150,101,20,194,225,283,16,435,296,248,199,484,64,65,112,42,183,74,464,418,83,140,446,358,447,6,113,433,85,421,422,467,90,401,124,301,154,480,499,184,370,77,316,17,141,314,469,472,117,8,346,391,331,259,37,481,311,274,369,497,448,431,437,160,234,479,308,476,488,205,91,105,267,220,40,397,403,312,58,11,281,27,315,157,72,382,1,434,307,47,180,282,419,376,303&cmd=ddkkekdkekfdkkekddkkfdddkfkddkddddkfdkdkkdddkdddkfkekekekddkfkekdddkekfdkfddkdddkkfkfkekfdddkekfkfkkekddkkdkdkddkdkfdkekdddddkdkddddkfdkkddkfkddddddddkekdkekkfkdkdkddkdddkdddkkddkddkdkkkfdkdddkdkfddddddkfkfdddkfdkekfdddddkfddkekfkekfddkddkfddkkfddddkddddkfkddkdddddkekfkkddddddkekddddkdddkkddddkdddddkdddkekfdkkkekfkkfkdddkddkekkfdkfdkfdkfkkdkfdddkekekekekfdkekkddkddkfdkfdkkkfdkekfkdkdkekfkdddddddkfddkekddkfdkekfkfkkfkkdddddkekfddkdkekdkekekkfdkdddkfkkkekkekddkkfddkkfkdddkdkfkfdkfkdkkfddkekddddkddddddddkfdddddkkfdkdddkkdkdkekdkddkkfdddkkkkekfkdkekdkkkekkfkkekekfdkekekfdkkdkfkkekkekekkekddkfdkekdddddkkkkekfkkkfkkekfkfkfdkdkekdkekekekkekdkkkddkekekekfddkekkkkekkkdkkekekkkkkfddkekfdkkekkkfkekfkkekkekkekkekkekekkfkekfddkkkkfkdkddkekkkekkkfkekkkekkekfkkkfkekekkekekfkkfkkkdkkkkekekkdkkkdkfkfkfkfdddkkdkddkdkekkddkkfkdkekkkkekekfkekdkkdkkddddkfdddddkfdkekekfdkekekekdkekkfdddkdkfdkkkkfkekkekfkekdkekekkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkjjdjjjdjgjgjdddjfejjeeejggggjjigjijhddjijhddjfffdjffffjffddjddjiiijhjffffejfdjfejffjggjdjjddddddjfdjhhhddjhjddddddjddjhhjffffjfddjfeejeeeejfejfffffdjeeggggjeggjeeeegggjffeeejfeeeejeeegjiiiggggjiigjegggjiiggggggggjihhjhhjgggggjeegjdjigggggjihjhhhhdjhhhhhhhhhhjhjhhhhhhjhddddjfffffdddjfffdddjfddjjddjgggggggjiiiiihhhhhhjffdddddddddjhhdddjfffffffddjhhhhhhhddddddjffffdddjffdddjhddddjhjhdjigggjhjiiiiiiggjiiiiigggggjigggggggggggggggjhdjiggggggggggggjeeeeeeggggggggggggjeegggjiiijigjgggjiigggjijfjiigggggggggjddddddddddddddddddddddddddddjigggggggggggjhdjhjhddjijhjhhjhhdjdddjhjhhdjigjhddjhddddjihjhjhddjhdddjfddjdjihhhhjihjiihjeggjigggjgjjfdjiggggjiijegggjhhhdddddddddddddjhjiijddddddjhddjhhjfddddjihhhjiiggjhhddddjhhhddddjiiiigjiigjhdddjiiiihhhhjhhdjhhhddddjhhhdddjfddddjffdddjddddjijhhdddjiiihjhhdjiggjihhjhhdjhhhjiiiigjhdjhhdddddddddjffffffdddjfejhhdddddjdddjfdjffdjgggjffffffjeeejgjffdjdddjhhdjigggggggggggjhhdjiiiiiiiiiiiiiihhhjhhdddddddddjffddddddddddjhhhjffffdddddjfddjddjejihhhhhjeeeeeeeeeggggggggggggggggggggggggggggggggggggggggggjiiiiiiigggggggggggggjigggjiggjgggjffeeeejddjiggggggggggjigjijihjdddddjijggggjjjdjgjddjfjjeegjddjdjfejffjeejdddjffejeeggjegjegjfdjiiiigjgjegggjgjhhjijhdddjhhdddddjiiijhhdddjfdddjfddjffddjeggggjjfeeeejigggggjejiggggjgjhdjfffffffffeeeeejeeegjiggjfejfdddjffffeeeeeejeeeeeeeeggjfdddddddjiigggggggjiiiiiiigjhhhddddjhhhhdddjfddddjfddddddddddddddddddddddddddddddddddjhhhhjigggjfffffffeeeejfddjffdddddjhddddjhjigjiigjhhhddjhhhddjhjiiijiggjiiiihjhhhhhddddddjihhhhjffffddddjfffdjeeggjfdddddjfddddjdjgjjhhjiiiijiiigjhhhhhdjfddddddddjfffjddddjejhhdjdddjddjhdjiijggjiggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggjhjhjhddjijhdjhhdjijijhhhjihhjhhhddjihhjfffffffjddddddjhjhddjhjiiijigjgjdjiggjihjihhjiiijiiihhhhhhhjhhhhhhhddjhhhdddddjffffffjfffjeejjjfffddddjfdjiihhhjhhhjiiiihhhjhdddddjhddjffdddjfffddjdjgjgjddjjhhhhhhdjhddjdddddjddddjfjdjhddjiiigjiiiiihhjhhhddddjiiiijiiiiijhhdjhhhhjeeeggggggjffeeeeeeeeeejeeegggggjiiggjigggggggjiiijgjhhjgggjiihhjeegggjggjdjiiihhhhhhhhhhhhhhhhhjfddddddddddjfddddddjfeejffffejffddjhhhhhhhddddjhhhjihhhjhhdddddddddjiggggggggggggggggggggggjffdddddddddddddddddddddddddddddddddddddddddddddddddddddjdjjddddjffffdjffdjhdddjihhjiijigjddddddddjhdjggggggggggggggggggjdjgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggjjfjjfdjejggjddjdddddjdjjejgjgjddjjhhhjhdddjfffffjffjeeejeeggggjgggggjgjddjeeeegjjfeeejddjeeeejfffejfjdddddjfffejgjegjeeeeeeegjffffddddjhddjffdddjhhhdjdddjiiggggjhhhhhhdjfdddjiiigggggjhhhhhdjhhhhhhhhdddjiiiigggjiiiiiiihhhjhdjhhhhhhhhhhhhjiiiiigjiiiiigjiijiiijigjhddjhjiigjgjegjjddddddjfffejffjffeejeeeeejejiggjegjegjeejddddjfdjiiiiiggjgggjiihhjhhhhdjiiijfffdddddddjfddjddddjfdddddddddddjffeejffdjfddjhddjhhjhddjhdjffdddjfffffejgggggggggggggggggggggjigggggggggggggggggggggggggggggjigjfddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddjddjfddjdddddjggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg)
 -- 4068
