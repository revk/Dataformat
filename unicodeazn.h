static const char * unicode_space="\011\012\013\014\015                  　";
static const char * const unicode_azn[36]={
	"AaÀÁÂÃÄÅàáâãäåĀāĂăĄąǍǎǞǟǠǡǺǻȀȁȂȃȦȧȺͣᶏᷲḀḁẚẠạẢảẤấẦầẨẩẪẫẬậẮắẰằẲẳẴẵẶặₐ⒜ⒶⓐⱥꬱＡａ𝐀𝐚𝐴𝑎𝑨𝒂𝒜𝒶𝓐𝓪𝔄𝔞𝔸𝕒𝕬𝖆𝖠𝖺𝗔𝗮𝘈𝘢𝘼𝙖𝙰𝚊🄐🄰🅐🅰󠁁󠁡",
	"BbƀƁƂƃɃɓᵬᶀᷨḂḃḄḅḆḇ⒝ⒷⓑꞖꞗＢｂ𝐁𝐛𝐵𝑏𝑩𝒃𝒷𝓑𝓫𝔅𝔟𝔹𝕓𝕭𝖇𝖡𝖻𝗕𝗯𝘉𝘣𝘽𝙗𝙱𝚋🄑🄱🅑🅱󠁂󠁢",
	"CcÇçĆćĈĉĊċČčƇƈȻȼɕͨᷗḈḉ⒞ⒸⓒꞒꞓꞔꟄＣｃ𝐂𝐜𝐶𝑐𝑪𝒄𝒞𝒸𝓒𝓬𝔠𝕔𝕮𝖈𝖢𝖼𝗖𝗰𝘊𝘤𝘾𝙘𝙲𝚌𝼝🄒🄫🄲🅒🅲󠁃󠁣",
	"DdĎďĐđƊƋƌǅǲȡɖɗͩᵭᶁᶑḊḋḌḍḎḏḐḑḒḓ⒟ⒹⓓꟇꟈＤｄ𝐃𝐝𝐷𝑑𝑫𝒅𝒟𝒹𝓓𝓭𝔇𝔡𝔻𝕕𝕯𝖉𝖣𝖽𝗗𝗱𝘋𝘥𝘿𝙙𝙳𝚍🄓🄳🅓🅳🆥󠁄󠁤",
	"EeÈÉÊËèéêëĒēĔĕĖėĘęĚěȄȅȆȇȨȩɆɇͤᶒḔḕḖḗḘḙḚḛḜḝẸẹẺẻẼẽẾếỀềỂểỄễỆệₑ⒠ⒺⓔⱸꬴＥｅ𝐄𝐞𝐸𝑒𝑬𝒆𝓔𝓮𝔈𝔢𝔼𝕖𝕰𝖊𝖤𝖾𝗘𝗲𝘌𝘦𝙀𝙚𝙴𝚎🄔🄴🅔🅴󠁅󠁥",
	"FfƑƒᵮᶂᷫḞḟ⒡ⒻⓕꞘꞙＦｆ𝐅𝐟𝐹𝑓𝑭𝒇𝒻𝓕𝓯𝔉𝔣𝔽𝕗𝕱𝖋𝖥𝖿𝗙𝗳𝘍𝘧𝙁𝙛𝙵𝚏🄕🄵🅕🅵󠁆󠁦",
	"GgĜĝĞğĠġĢģƓǤǥǦǧǴǵɠᶃᷚḠḡ⒢ⒼⓖꞠꞡＧｇ𝐆𝐠𝐺𝑔𝑮𝒈𝒢𝓖𝓰𝔊𝔤𝔾𝕘𝕲𝖌𝖦𝗀𝗚𝗴𝘎𝘨𝙂𝙜𝙶𝚐🄖🄶🅖🅶󠁇󠁧",
	"HhĤĥĦħȞȟɦͪḢḣḤḥḦḧḨḩḪḫẖₕ⒣ⒽⓗⱧⱨꞕꞪＨｈ𝐇𝐡𝐻𝑯𝒉𝒽𝓗𝓱𝔥𝕙𝕳𝖍𝖧𝗁𝗛𝗵𝘏𝘩𝙃𝙝𝙷𝚑🄗🄷🅗🅷󠁈󠁨",
	"IiÌÍÎÏìíîïĨĩĪīĬĭĮįİƗǏǐȈȉȊȋɨͥᵢᵻᶖḬḭḮḯỈỉỊịⁱ⒤ⒾⓘꟾＩｉ𝐈𝐢𝐼𝑖𝑰𝒊𝒾𝓘𝓲𝔦𝕀𝕚𝕴𝖎𝖨𝗂𝗜𝗶𝘐𝘪𝙄𝙞𝙸𝚒𝼚🄘🄸🅘🅸󠁉󠁩",
	"JjĴĵǰɈɉʝ⒥ⒿⓙⱼꞲＪｊ𝐉𝐣𝐽𝑗𝑱𝒋𝒥𝒿𝓙𝓳𝔍𝔧𝕁𝕛𝕵𝖏𝖩𝗃𝗝𝗷𝘑𝘫𝙅𝙟𝙹𝚓🄙🄹🅙🅹󠁊󠁪",
	"KkĶķƘƙǨǩᶄᷜḰḱḲḳḴḵₖ⒦ⓀⓚⱩⱪꝀꝁꝂꝃꝄꝅꞢꞣＫｋ𝐊𝐤𝐾𝑘𝑲𝒌𝒦𝓀𝓚𝓴𝔎𝔨𝕂𝕜𝕶𝖐𝖪𝗄𝗞𝗸𝘒𝘬𝙆𝙠𝙺𝚔🄚🄺🅚🅺󠁋󠁫",
	"LlĹĺĻļĽľĿŀŁłƚǈȴȽɫɬɭᶅᷝᷬḶḷḸḹḺḻḼḽₗ⒧ⓁⓛⱠⱡⱢꝈꝉꞎꞭꬷꬸꬹＬｌ𝐋𝐥𝐿𝑙𝑳𝒍𝓁𝓛𝓵𝔏𝔩𝕃𝕝𝕷𝖑𝖫𝗅𝗟𝗹𝘓𝘭𝙇𝙡𝙻𝚕𝼑𝼓🄛🄻🅛🅻󠁌󠁬",
	"MmɱͫᵯᶆḾḿṀṁṂṃₘ⒨ⓂⓜⱮꬺＭｍ𝐌𝐦𝑀𝑚𝑴𝒎𝓂𝓜𝓶𝔐𝔪𝕄𝕞𝕸𝖒𝖬𝗆𝗠𝗺𝘔𝘮𝙈𝙢𝙼𝚖🄜🄼🅜🅼󠁍󠁭",
	"NnÑñŃńŅņŇňŉƝƞǋǸǹȠȵɲɳᵰᶇᷠṄṅṆṇṈṉṊṋⁿₙ⒩ⓃⓝꞐꞑꞤꞥꬻＮｎ𝐍𝐧𝑁𝑛𝑵𝒏𝒩𝓃𝓝𝓷𝔑𝔫𝕟𝕹𝖓𝖭𝗇𝗡𝗻𝘕𝘯𝙉𝙣𝙽𝚗🄝🄽🅝🅽󠁎󠁮",
	"OoÒÓÔÕÖØòóôõöøŌōŎŏŐőƟƠơǑǒǪǫǬǭǾǿȌȍȎȏȪȫȬȭȮȯȰȱͦᷭᷳṌṍṎṏṐṑṒṓỌọỎỏỐốỒồỔổỖỗỘộỚớỜờỞởỠỡỢợₒ⒪ⓄⓞⱺꝊꝋꝌꝍＯｏ𝐎𝐨𝑂𝑜𝑶𝒐𝒪𝓞𝓸𝔒𝔬𝕆𝕠𝕺𝖔𝖮𝗈𝗢𝗼𝘖𝘰𝙊𝙤𝙾𝚘𝼛🄞🄾🅞🅾󠁏󠁯",
	"PpƤƥᵱᵽᶈᷮṔṕṖṗₚ⒫ⓅⓟⱣꝐꝑꝒꝓꝔꝕＰｐ𝐏𝐩𝑃𝑝𝑷𝒑𝒫𝓅𝓟𝓹𝔓𝔭𝕡𝕻𝖕𝖯𝗉𝗣𝗽𝘗𝘱𝙋𝙥𝙿𝚙🄟🄿🅟🅿🆊󠁐󠁰",
	"Qqɋʠ⒬ⓆⓠꝖꝗꝘꝙＱｑ𝐐𝐪𝑄𝑞𝑸𝒒𝒬𝓆𝓠𝓺𝔔𝔮𝕢𝕼𝖖𝖰𝗊𝗤𝗾𝘘𝘲𝙌𝙦𝚀𝚚🄠🅀🅠🆀󠁑󠁱",
	"RrŔŕŖŗŘřȐȑȒȓɌɍɼɽɾͬᵣᵲᵳᶉ᷊ᷣṘṙṚṛṜṝṞṟ⒭ⓇⓡⱤꝚꝛꞦꞧꭇꭉＲｒ𝐑𝐫𝑅𝑟𝑹𝒓𝓇𝓡𝓻𝔯𝕣𝕽𝖗𝖱𝗋𝗥𝗿𝘙𝘳𝙍𝙧𝚁𝚛𝼖🄡🄬🅁🅡🆁󠁒󠁲",
	"SsŚśŜŝŞşŠšȘșȿʂᵴᶊᷤṠṡṢṣṤṥṦṧṨṩₛ⒮ⓈⓢⱾꞨꞩꟅꟉꟊＳｓ𝐒𝐬𝑆𝑠𝑺𝒔𝒮𝓈𝓢𝓼𝔖𝔰𝕊𝕤𝕾𝖘𝖲𝗌𝗦𝘀𝘚𝘴𝙎𝙨𝚂𝚜𝼞🄢🄪🅂🅢🆂󠁓󠁳",
	"TtŢţŤťŦŧƫƬƭƮȚțȶȾʈͭᵵṪṫṬṭṮṯṰṱẗₜ⒯ⓉⓣⱦＴｔ𝐓𝐭𝑇𝑡𝑻𝒕𝒯𝓉𝓣𝓽𝔗𝔱𝕋𝕥𝕿𝖙𝖳𝗍𝗧𝘁𝘛𝘵𝙏𝙩𝚃𝚝𝼉🄣🅃🅣🆃󠁔󠁴",
	"UuÙÚÛÜùúûüŨũŪūŬŭŮůŰűŲųƯưǓǔǕǖǗǘǙǚǛǜȔȕȖȗɄʉͧᵤᵾᶙᷰᷴṲṳṴṵṶṷṸṹṺṻỤụỦủỨứỪừỬửỮữỰự⒰ⓊⓤꞸꞹꭎꭏꭒＵｕ𝐔𝐮𝑈𝑢𝑼𝒖𝒰𝓊𝓤𝓾𝔘𝔲𝕌𝕦𝖀𝖚𝖴𝗎𝗨𝘂𝘜𝘶𝙐𝙪𝚄𝚞🄤🅄🅤🆄󠁕󠁵",
	"VvƲʋͮᵥᶌṼṽṾṿ⒱ⓋⓥⱱⱴꝞꝟＶｖ𝐕𝐯𝑉𝑣𝑽𝒗𝒱𝓋𝓥𝓿𝔙𝔳𝕍𝕧𝖁𝖛𝖵𝗏𝗩𝘃𝘝𝘷𝙑𝙫𝚅𝚟🄥🅅🅥🆅󠁖󠁶",
	"WwŴŵᪿᷱẀẁẂẃẄẅẆẇẈẉẘ⒲ⓌⓦⱲⱳＷｗ𝐖𝐰𝑊𝑤𝑾𝒘𝒲𝓌𝓦𝔀𝔚𝔴𝕎𝕨𝖂𝖜𝖶𝗐𝗪𝘄𝘞𝘸𝙒𝙬𝚆𝚠🄦🅆🅦🆆󠁗󠁷",
	"XxͯᶍẊẋẌẍₓ⒳ⓍⓧꭖꭗꭘꭙＸｘ𝐗𝐱𝑋𝑥𝑿𝒙𝒳𝓍𝓧𝔁𝔛𝔵𝕏𝕩𝖃𝖝𝖷𝗑𝗫𝘅𝘟𝘹𝙓𝙭𝚇𝚡🄧🅇🅧🆇󠁘󠁸",
	"YyÝýÿŶŷŸƳƴȲȳɎɏẎẏẙỲỳỴỵỶỷỸỹỾỿ⒴ⓎⓨꭚＹｙ𝐘𝐲𝑌𝑦𝒀𝒚𝒴𝓎𝓨𝔂𝔜𝔶𝕐𝕪𝖄𝖞𝖸𝗒𝗬𝘆𝘠𝘺𝙔𝙮𝚈𝚢🄨🅈🅨🆈󠁙󠁹",
	"ZzŹźŻżŽžƵƶȤȥɀʐʑᵶᶎᷦẐẑẒẓẔẕ⒵ⓏⓩⱫⱬⱿꟆＺｚ𝐙𝐳𝑍𝑧𝒁𝒛𝒵𝓏𝓩𝔃𝔷𝕫𝖅𝖟𝖹𝗓𝗭𝘇𝘡𝘻𝙕𝙯𝚉𝚣🄩🅉🅩🆉󠁚󠁺",
	"0٠۰߀०০੦૦୦௦౦౸೦൦෦๐໐༠၀႐០᠐᥆᧐᪀᪐᭐᮰᱀᱐⓪⓿꘠꣐꣠꤀꧐꧰꩐꯰０𐒠𐴰𑁦𑃰𑄶𑇐𑋰𑍦𑑐𑓐𑙐𑛀𑜰𑣠𑥐𑱐𑵐𑶠𖩠𖫀𖭐𖺀𝟎𝟘𝟢𝟬𝟶𞅀𞋰𞥐🄀🄁🄋🄌🯰󠀰",
	"1١۱߁१১੧૧୧௧౧౹౼೧൧෧๑໑༡၁႑፩១᠑᥇᧑᧚᪁᪑᭑᮱᱁᱑①⑴⒈⓵❶➀➊꘡꣑꣡꤁꧑꧱꩑꯱１𐋡𐒡𐩀𐴱𐹠𑁧𑃱𑄷𑇑𑇡𑋱𑍧𑑑𑓑𑙑𑛁𑜱𑣡𑥑𑱑𑵑𑶡𖩡𖫁𖭑𖺁𖺔𝍠𝍩𝟏𝟙𝟣𝟭𝟷𞅁𞋱𞣇𞥑🄂🯱󠀱",
	"2٢۲ݳݵݸݺ߂२২੨૨୨௨౨౺౽೨൨෨๒໒༢၂႒፪២᠒᥈᧒᪂᪒᭒᮲᱂᱒↊②⑵⒉⓶❷➁➋꘢꣒꣢꤂꧒꧲꩒꯲２𐋢𐒢𐩁𐴲𐹡𑁨𑃲𑄸𑇒𑇢𑋲𑍨𑑒𑓒𑙒𑛂𑜲𑣢𑥒𑱒𑵒𑶢𖩢𖫂𖭒𖺂𖺕𝍡𝍪𝟐𝟚𝟤𝟮𝟸𞅂𞋲𞣈𞥒🄃🯲󠀲",
	"3٣۳ݴݶݹݻ߃३৩੩૩୩௩౩౻౾೩൩෩๓໓༣၃႓፫៣᠓᥉᧓᪃᪓᭓᮳᱃᱓↋③⑶⒊⓷❸➂➌꘣꣓꣣꤃꧓꧳꩓꯳３𐋣𐒣𐩂𐴳𐹢𑁩𑃳𑄹𑇓𑇣𑋳𑍩𑑓𑓓𑙓𑛃𑜳𑣣𑥓𑱓𑵓𑶣𖩣𖫃𖭓𖺃𖺖𝍢𝍫𝟑𝟛𝟥𝟯𝟹𞅃𞋳𞣉𞥓🄄🯳󠀳",
	"4٤۴ݷݼݽ߄४৪੪૪୪௪౪೪൪෪๔໔༤၄႔፬៤᠔᥊᧔᪄᪔᭔᮴᱄᱔④⑷⒋⓸❹➃➍꘤꣔꣤꤄꧔꧴꩔꯴４𐋤𐒤𐩃𐴴𐹣𑁪𑃴𑄺𑇔𑇤𑋴𑍪𑑔𑓔𑙔𑛄𑜴𑣤𑥔𑱔𑵔𑶤𖩤𖫄𖭔𖺄𝍣𝍬𝟒𝟜𝟦𝟰𝟺𞅄𞋴𞣊𞥔🄅🯴󠀴",
	"5٥۵߅५৫੫૫୫௫౫೫൫෫๕໕༥၅႕፭៥᠕᥋᧕᪅᪕᭕᮵᱅᱕⑤⑸⒌⓹❺➄➎꘥꣕꣥꤅꧕꧵꩕꯵５𐋥𐒥𐴵𐹤𑁫𑃵𑄻𑇕𑇥𑋵𑍫𑑕𑓕𑙕𑛅𑜵𑣥𑥕𑱕𑵕𑶥𖩥𖫅𖭕𖺅𝍤𝍭𝟓𝟝𝟧𝟱𝟻𞅅𞋵𞣋𞥕🄆🯵󠀵",
	"6٦۶߆६৬੬૬୬௬౬೬൬෬๖໖༦၆႖፮៦᠖᥌᧖᪆᪖᭖᮶᱆᱖⑥⑹⒍⓺❻➅➏꘦꣖꣦꤆꧖꧶꩖꯶６𐋦𐒦𐴶𐹥𑁬𑃶𑄼𑇖𑇦𑋶𑍬𑑖𑓖𑙖𑛆𑜶𑣦𑥖𑱖𑵖𑶦𖩦𖫆𖭖𖺆𝍥𝍮𝟔𝟞𝟨𝟲𝟼𞅆𞋶𞣌𞥖🄇🯶󠀶",
	"7٧۷߇७৭੭૭୭௭౭೭൭෭๗໗༧၇႗፯៧᠗᥍᧗᪇᪗᭗᮷᱇᱗⑦⑺⒎⓻❼➆➐꘧꣗꣧꤇꧗꧷꩗꯷７𐋧𐒧𐴷𐹦𑁭𑃷𑄽𑇗𑇧𑋷𑑗𑓗𑙗𑛇𑜷𑣧𑥗𑱗𑵗𑶧𖩧𖫇𖭗𖺇𝍦𝍯𝟕𝟟𝟩𝟳𝟽𞅇𞋷𞣍𞥗🄈🯷󠀷",
	"8٨۸߈८৮੮૮୮௮౮೮൮෮๘໘༨၈႘፰៨᠘᥎᧘᪈᪘᭘᮸᱈᱘⑧⑻⒏⓼❽➇➑꘨꣘꣨꤈꧘꧸꩘꯸８𐋨𐒨𐴸𐹧𑁮𑃸𑄾𑇘𑇨𑋸𑑘𑓘𑙘𑛈𑜸𑣨𑥘𑱘𑵘𑶨𖩨𖫈𖭘𖺈𝍧𝍰𝟖𝟠𝟪𝟴𝟾𞅈𞋸𞣎𞥘🄉🯸󠀸",
	"9٩۹߉९৯੯૯୯௯౯೯൯෯๙໙༩၉႙፱៩᠙᥏᧙᪉᪙᭙᮹᱉᱙⑨⑼⒐⓽❾➈➒꘩꣙꣩꤉꧙꧹꩙꯹９𐋩𐒩𐴹𐹨𑁯𑃹𑄿𑇙𑇩𑋹𑑙𑓙𑙙𑛉𑜹𑣩𑥙𑱙𑵙𑶩𖩩𖫉𖭙𖺉𝍨𝍱𝟗𝟡𝟫𝟵𝟿𞅉𞋹𞣏𞥙🄊🯹󠀹",
};