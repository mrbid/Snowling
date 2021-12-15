
#ifndef minball_H
#define minball_H

const GLfloat minball_vertices[] = {0.000000,0.000000,0.047699,0.001758,0.005409,0.047359,-0.004602,0.003343,0.047359,-0.034515,0.025077,0.021332,-0.036813,0.020059,0.022752,-0.032211,0.023403,0.026267,0.005688,0.000000,0.047359,0.001758,-0.005409,0.047359,-0.004602,-0.003343,0.047359,-0.037899,0.023403,0.017064,0.013183,0.040575,0.021332,0.010546,0.043276,0.017064,0.007702,0.041210,0.022752,0.042663,0.000000,0.021332,0.044417,0.003343,0.017064,0.041573,0.005409,0.022752,0.013183,-0.040575,0.021332,0.016905,-0.041210,0.017064,0.017991,-0.037867,0.022752,-0.034515,-0.025077,0.021332,-0.033969,-0.028812,0.017064,-0.030454,-0.028812,0.022752,-0.033969,0.028812,0.017064,0.016905,0.041210,0.017064,0.044417,-0.003343,0.017064,0.010546,-0.043276,0.017064,-0.037899,-0.023403,0.017064,-0.013183,0.040575,-0.021332,-0.012303,0.037866,-0.026267,-0.017991,0.037867,-0.022752,0.034515,0.025077,-0.021332,0.032211,0.023403,-0.026267,0.030454,0.028812,-0.022752,0.034515,-0.025077,-0.021332,0.032211,-0.023403,-0.026267,0.036813,-0.020059,-0.022752,-0.013183,-0.040575,-0.021332,-0.012303,-0.037866,-0.026267,-0.007702,-0.041210,-0.022752,-0.042663,0.000000,-0.021332,-0.039815,0.000000,-0.026267,-0.041573,-0.005409,-0.022752,-0.005688,0.000000,-0.047359,0.000000,0.000000,-0.047699,-0.001758,-0.005409,-0.047359,-0.011980,0.000000,-0.046170,-0.007927,-0.005760,-0.046682,-0.018587,0.000000,-0.043929,-0.014652,-0.006035,-0.044990,-0.025077,0.000000,-0.040575,-0.021530,-0.006188,-0.042111,-0.030979,0.000000,-0.036270,-0.028037,-0.006188,-0.038090,-0.035939,0.000000,-0.031363,-0.033688,-0.006035,-0.033225,-0.038208,-0.005760,-0.027967,-0.003702,-0.011393,-0.046170,-0.010267,-0.012070,-0.044990,-0.005744,-0.017677,-0.043929,-0.017258,-0.012538,-0.042664,-0.012538,-0.018564,-0.042111,-0.007749,-0.023849,-0.040576,-0.024171,-0.012707,-0.039109,-0.019554,-0.019061,-0.039109,-0.014549,-0.024752,-0.038090,-0.009573,-0.029462,-0.036271,-0.030441,-0.012538,-0.034516,-0.026235,-0.019061,-0.034980,-0.021332,-0.025077,-0.034516,-0.016149,-0.030174,-0.033225,-0.011105,-0.034179,-0.031363,-0.035649,-0.012070,-0.029304,-0.032058,-0.018564,-0.030048,-0.027562,-0.024752,-0.030048,-0.022495,-0.030174,-0.029304,-0.017285,-0.034558,-0.027968,-0.039640,-0.011393,-0.023959,-0.036722,-0.017677,-0.024783,-0.032826,-0.023849,-0.025077,-0.028160,-0.029462,-0.024783,-0.023085,-0.034180,-0.023959,-0.017991,-0.037867,-0.022752,0.004602,-0.003343,-0.047359,0.003028,-0.009319,-0.046682,0.001212,-0.015799,-0.044990,-0.000768,-0.022389,-0.042111,-0.002778,-0.028577,-0.038090,-0.004670,-0.033904,-0.033225,-0.006329,-0.038118,-0.027968,0.009692,-0.007041,-0.046170,0.008306,-0.013494,-0.044990,0.015037,-0.010925,-0.043929,0.006592,-0.020287,-0.042664,0.013781,-0.017661,-0.042111,0.020288,-0.014740,-0.040576,0.004616,-0.026914,-0.039109,0.012085,-0.024487,-0.039109,0.019045,-0.021486,-0.038090,0.025062,-0.018208,-0.036271,0.002518,-0.032826,-0.034516,0.010021,-0.030841,-0.034980,0.017258,-0.028037,-0.034516,0.023707,-0.024683,-0.033225,0.029075,-0.021124,-0.031363,0.000463,-0.037634,-0.029304,0.007749,-0.036226,-0.030048,0.015024,-0.033862,-0.030048,0.021746,-0.030718,-0.029304,0.027526,-0.027118,-0.027968,-0.001414,-0.041221,-0.023959,0.005465,-0.040387,-0.024783,0.012539,-0.038589,-0.025077,0.019319,-0.035886,-0.024783,0.025373,-0.032517,-0.023959,0.030454,-0.028812,-0.022752,0.004602,0.003343,-0.047359,0.009799,0.000000,-0.046682,0.015401,-0.003730,-0.044990,0.021055,-0.007649,-0.042111,0.026319,-0.011473,-0.038090,0.030801,-0.014919,-0.033225,0.034296,-0.017798,-0.027968,0.009692,0.007041,-0.046170,0.015401,0.003730,-0.044990,0.015037,0.010925,-0.043929,0.021332,0.000000,-0.042664,0.021055,0.007649,-0.042111,0.020288,0.014740,-0.040576,0.027023,-0.003927,-0.039109,0.027023,0.003927,-0.039109,0.026319,0.011473,-0.038090,0.025062,0.018208,-0.036271,0.031997,-0.007749,-0.034516,0.032428,0.000000,-0.034980,0.031997,0.007749,-0.034516,0.030801,0.014919,-0.033225,0.029075,0.021124,-0.031363,0.035935,-0.011189,-0.029304,0.036847,-0.003824,-0.030048,0.036847,0.003824,-0.030048,0.035935,0.011189,-0.029304,0.034296,0.017798,-0.027968,0.038767,-0.014083,-0.023959,0.040099,-0.007283,-0.024783,0.040575,-0.000000,-0.025077,0.040099,0.007283,-0.024783,0.038767,0.014083,-0.023959,0.036813,0.020059,-0.022752,-0.001758,0.005409,-0.047359,0.003028,0.009319,-0.046682,0.008306,0.013494,-0.044990,0.013781,0.017661,-0.042111,0.019045,0.021486,-0.038090,0.023707,0.024683,-0.033225,0.027526,0.027118,-0.027968,-0.003702,0.011393,-0.046170,0.001212,0.015799,-0.044990,-0.005744,0.017677,-0.043929,0.006592,0.020287,-0.042664,-0.000768,0.022389,-0.042111,-0.007749,0.023849,-0.040576,0.012085,0.024487,-0.039109,0.004616,0.026914,-0.039109,-0.002778,0.028577,-0.038090,-0.009573,0.029462,-0.036271,0.017258,0.028037,-0.034516,0.010021,0.030841,-0.034980,0.002518,0.032826,-0.034516,-0.004670,0.033904,-0.033225,-0.011105,0.034179,-0.031363,0.021746,0.030718,-0.029304,0.015024,0.033862,-0.030048,0.007749,0.036226,-0.030048,0.000463,0.037634,-0.029304,-0.006329,0.038118,-0.027968,0.025373,0.032517,-0.023959,0.019319,0.035886,-0.024783,0.012539,0.038589,-0.025077,0.005465,0.040387,-0.024783,-0.001414,0.041221,-0.023959,-0.007702,0.041210,-0.022752,-0.007927,0.005760,-0.046682,-0.010267,0.012070,-0.044990,-0.012538,0.018564,-0.042111,-0.014549,0.024752,-0.038090,-0.016149,0.030174,-0.033225,-0.017285,0.034558,-0.027968,-0.014652,0.006035,-0.044990,-0.017258,0.012538,-0.042664,-0.021530,0.006188,-0.042111,-0.019554,0.019061,-0.039109,-0.024171,0.012707,-0.039109,-0.028037,0.006188,-0.038090,-0.021332,0.025077,-0.034516,-0.026235,0.019061,-0.034980,-0.030441,0.012538,-0.034516,-0.033688,0.006035,-0.033225,-0.022495,0.030174,-0.029304,-0.027562,0.024752,-0.030048,-0.032058,0.018564,-0.030048,-0.035649,0.012070,-0.029304,-0.038208,0.005760,-0.027967,-0.023085,0.034180,-0.023959,-0.028160,0.029462,-0.024783,-0.032826,0.023849,-0.025077,-0.036722,0.017677,-0.024783,-0.039640,0.011393,-0.023959,-0.041573,0.005409,-0.022752,-0.044417,-0.003343,-0.017064,-0.045630,-0.007041,-0.011980,-0.043108,-0.009319,-0.018168,-0.046016,-0.010925,-0.006196,-0.043955,-0.013494,-0.012691,-0.045365,-0.014740,-0.000000,-0.043829,-0.017661,-0.006507,-0.043649,-0.018209,0.006196,-0.042586,-0.021486,0.000000,-0.041055,-0.021124,0.011980,-0.040320,-0.024683,0.006346,-0.037325,-0.027118,0.012112,-0.040782,-0.015799,-0.019036,-0.041107,-0.020288,-0.013184,-0.037322,-0.022389,-0.019520,-0.040385,-0.024487,-0.006681,-0.037045,-0.026914,-0.013361,-0.032826,-0.028577,-0.019520,-0.038590,-0.028037,0.000000,-0.035769,-0.030841,-0.006681,-0.031998,-0.032826,-0.013184,-0.027629,-0.033904,-0.019037,-0.035935,-0.030718,0.006346,-0.033594,-0.033862,-0.000000,-0.030341,-0.036226,-0.006507,-0.026417,-0.037634,-0.012691,-0.022184,-0.038118,-0.018169,-0.032777,-0.032517,0.011980,-0.030806,-0.035886,0.006196,-0.028037,-0.038589,0.000000,-0.024610,-0.040388,-0.006196,-0.020797,-0.041221,-0.011980,-0.016905,-0.041210,-0.017064,-0.010546,-0.043276,-0.017064,-0.007404,-0.045573,-0.011980,-0.004458,-0.043878,-0.018169,-0.003829,-0.047140,-0.006196,-0.000749,-0.045974,-0.012691,-0.000000,-0.047699,-0.000000,0.003253,-0.047141,-0.006507,0.003829,-0.047140,0.006196,0.007275,-0.047141,0.000000,0.007404,-0.045573,0.011980,0.011016,-0.045974,0.006346,0.014257,-0.043878,0.012112,0.002424,-0.043669,-0.019037,0.006592,-0.045365,-0.013184,0.009760,-0.042414,-0.019520,0.010809,-0.045975,-0.006681,0.014150,-0.043548,-0.013361,0.017034,-0.040050,-0.019520,0.014740,-0.045365,0.000000,0.018279,-0.043548,-0.006681,0.021332,-0.040575,-0.013184,0.023707,-0.036753,-0.019037,0.018110,-0.043669,0.006346,0.021824,-0.042414,0.000000,0.025077,-0.040050,-0.006507,0.027629,-0.036753,-0.012691,0.029397,-0.032877,-0.018169,0.020797,-0.041221,0.011980,0.024610,-0.040388,0.006196,0.028037,-0.038589,0.000000,0.030806,-0.035886,-0.006196,0.032777,-0.032517,-0.011980,0.033969,-0.028812,-0.017064,0.037899,-0.023403,-0.017064,0.041055,-0.021124,-0.011980,0.040353,-0.017798,-0.018169,0.043649,-0.018209,-0.006196,0.043492,-0.014919,-0.012691,0.045365,-0.014740,-0.000000,0.045839,-0.011473,-0.006507,0.046016,-0.010925,0.006196,0.047082,-0.007649,-0.000000,0.045630,-0.007041,0.011980,0.047128,-0.003730,0.006345,0.046136,0.000000,0.012112,0.042280,-0.011189,-0.019036,0.045181,-0.007749,-0.013184,0.043354,-0.003824,-0.019520,0.047066,-0.003927,-0.006681,0.045790,0.000000,-0.013361,0.043354,0.003824,-0.019520,0.047699,0.000000,-0.000000,0.047065,0.003927,-0.006681,0.045181,0.007749,-0.013184,0.042280,0.011189,-0.019037,0.047128,0.003730,0.006345,0.047082,0.007649,-0.000000,0.045839,0.011473,-0.006507,0.043492,0.014919,-0.012691,0.040353,0.017798,-0.018169,0.045630,0.007041,0.011980,0.046016,0.010925,0.006196,0.045365,0.014740,0.000000,0.043649,0.018209,-0.006196,0.041055,0.021124,-0.011980,0.037899,0.023403,-0.017064,0.033969,0.028812,-0.017064,0.032777,0.032517,-0.011980,0.029397,0.032877,-0.018169,0.030806,0.035886,-0.006196,0.027629,0.036753,-0.012691,0.028037,0.038589,-0.000000,0.025077,0.040050,-0.006507,0.024610,0.040388,0.006196,0.021824,0.042414,0.000000,0.020797,0.041221,0.011980,0.018110,0.043669,0.006346,0.014257,0.043878,0.012112,0.023707,0.036753,-0.019037,0.021332,0.040575,-0.013184,0.017035,0.040050,-0.019520,0.018279,0.043548,-0.006681,0.014150,0.043548,-0.013361,0.009760,0.042414,-0.019520,0.014740,0.045365,0.000000,0.010810,0.045975,-0.006681,0.006592,0.045365,-0.013184,0.002424,0.043669,-0.019037,0.011016,0.045974,0.006346,0.007275,0.047141,0.000000,0.003253,0.047141,-0.006507,-0.000749,0.045974,-0.012691,-0.004458,0.043878,-0.018169,0.007404,0.045573,0.011980,0.003829,0.047140,0.006196,0.000000,0.047699,0.000000,-0.003829,0.047140,-0.006196,-0.007404,0.045573,-0.011980,-0.010546,0.043276,-0.017064,-0.016905,0.041210,-0.017064,-0.020797,0.041221,-0.011980,-0.022184,0.038118,-0.018169,-0.024610,0.040388,-0.006196,-0.026417,0.037634,-0.012691,-0.028037,0.038589,-0.000000,-0.030341,0.036226,-0.006507,-0.030806,0.035886,0.006196,-0.033594,0.033862,0.000000,-0.032777,0.032517,0.011980,-0.035935,0.030718,0.006346,-0.037325,0.027118,0.012112,-0.027629,0.033904,-0.019037,-0.031998,0.032826,-0.013184,-0.032826,0.028577,-0.019520,-0.035769,0.030841,-0.006681,-0.037045,0.026914,-0.013361,-0.037322,0.022389,-0.019520,-0.038590,0.028037,0.000000,-0.040385,0.024487,-0.006681,-0.041107,0.020288,-0.013184,-0.040782,0.015799,-0.019036,-0.040320,0.024683,0.006346,-0.042586,0.021486,0.000000,-0.043829,0.017661,-0.006507,-0.043955,0.013494,-0.012691,-0.043108,0.009319,-0.018168,-0.041055,0.021124,0.011980,-0.043649,0.018209,0.006196,-0.045365,0.014740,0.000000,-0.046016,0.010925,-0.006196,-0.045630,0.007041,-0.011980,-0.044417,0.003343,-0.017064,-0.014257,-0.043878,-0.012112,-0.018110,-0.043669,-0.006346,-0.021824,-0.042414,0.000000,-0.025077,-0.040050,0.006507,-0.027629,-0.036753,0.012691,-0.029397,-0.032877,0.018169,-0.011016,-0.045974,-0.006346,-0.014740,-0.045365,0.000000,-0.007275,-0.047141,-0.000000,-0.018279,-0.043548,0.006681,-0.010810,-0.045975,0.006681,-0.003253,-0.047141,0.006507,-0.021332,-0.040575,0.013184,-0.014150,-0.043548,0.013361,-0.006592,-0.045365,0.013184,0.000749,-0.045974,0.012691,-0.023707,-0.036753,0.019037,-0.017035,-0.040050,0.019520,-0.009760,-0.042414,0.019520,-0.002424,-0.043669,0.019037,0.004458,-0.043878,0.018169,-0.025373,-0.032517,0.023959,-0.019319,-0.035886,0.024783,-0.012539,-0.038589,0.025077,-0.005465,-0.040387,0.024783,0.001414,-0.041221,0.023959,0.007702,-0.041210,0.022752,0.037325,-0.027118,-0.012112,0.035935,-0.030718,-0.006346,0.033594,-0.033862,0.000000,0.030341,-0.036226,0.006507,0.026417,-0.037634,0.012691,0.022184,-0.038118,0.018169,0.040320,-0.024683,-0.006346,0.038590,-0.028037,0.000000,0.042586,-0.021486,-0.000000,0.035769,-0.030841,0.006681,0.040385,-0.024488,0.006681,0.043829,-0.017661,0.006507,0.031998,-0.032826,0.013184,0.037045,-0.026914,0.013361,0.041107,-0.020288,0.013184,0.043955,-0.013494,0.012691,0.027629,-0.033904,0.019037,0.032826,-0.028577,0.019520,0.037322,-0.022389,0.019520,0.040782,-0.015799,0.019036,0.043108,-0.009319,0.018168,0.023085,-0.034180,0.023959,0.028160,-0.029462,0.024783,0.032826,-0.023849,0.025077,0.036722,-0.017677,0.024783,0.039640,-0.011393,0.023959,0.041573,-0.005409,0.022752,0.037325,0.027118,-0.012112,0.040320,0.024683,-0.006346,0.042586,0.021486,0.000000,0.043829,0.017661,0.006507,0.043955,0.013494,0.012691,0.043108,0.009319,0.018168,0.035935,0.030718,-0.006346,0.038590,0.028037,-0.000000,0.033594,0.033862,-0.000000,0.040385,0.024488,0.006681,0.035769,0.030841,0.006681,0.030341,0.036226,0.006507,0.041107,0.020288,0.013184,0.037045,0.026914,0.013361,0.031998,0.032826,0.013184,0.026417,0.037634,0.012691,0.040782,0.015799,0.019036,0.037322,0.022389,0.019520,0.032826,0.028577,0.019520,0.027629,0.033904,0.019037,0.022184,0.038118,0.018169,0.039640,0.011393,0.023959,0.036722,0.017677,0.024783,0.032826,0.023849,0.025077,0.028160,0.029462,0.024783,0.023085,0.034180,0.023959,0.017991,0.037867,0.022752,-0.014257,0.043878,-0.012112,-0.011016,0.045974,-0.006346,-0.007275,0.047141,0.000000,-0.003253,0.047141,0.006507,0.000749,0.045974,0.012691,0.004458,0.043878,0.018169,-0.018110,0.043669,-0.006346,-0.014740,0.045365,-0.000000,-0.021824,0.042414,-0.000000,-0.010810,0.045975,0.006681,-0.018279,0.043548,0.006681,-0.025077,0.040050,0.006507,-0.006592,0.045365,0.013184,-0.014150,0.043548,0.013361,-0.021332,0.040575,0.013184,-0.027629,0.036753,0.012691,-0.002424,0.043669,0.019037,-0.009760,0.042414,0.019520,-0.017035,0.040050,0.019520,-0.023707,0.036753,0.019037,-0.029397,0.032877,0.018169,0.001414,0.041221,0.023959,-0.005465,0.040387,0.024783,-0.012539,0.038589,0.025077,-0.019319,0.035886,0.024783,-0.025373,0.032517,0.023959,-0.030454,0.028812,0.022752,-0.046136,0.000000,-0.012112,-0.047128,0.003730,-0.006345,-0.047082,0.007649,0.000000,-0.045839,0.011473,0.006507,-0.043492,0.014919,0.012691,-0.040353,0.017798,0.018169,-0.047128,-0.003730,-0.006345,-0.047699,0.000000,-0.000000,-0.047082,-0.007649,-0.000000,-0.047065,0.003927,0.006681,-0.047066,-0.003927,0.006681,-0.045839,-0.011473,0.006507,-0.045181,0.007749,0.013184,-0.045790,0.000000,0.013361,-0.045181,-0.007749,0.013184,-0.043492,-0.014919,0.012691,-0.042280,0.011189,0.019037,-0.043354,0.003824,0.019520,-0.043354,-0.003824,0.019520,-0.042280,-0.011189,0.019037,-0.040353,-0.017798,0.018169,-0.038767,0.014083,0.023959,-0.040099,0.007283,0.024783,-0.040575,0.000000,0.025077,-0.040099,-0.007283,0.024783,-0.038767,-0.014083,0.023959,-0.036813,-0.020059,0.022752,-0.032211,-0.023403,0.026267,-0.029075,-0.021124,0.031363,-0.027526,-0.027118,0.027968,-0.025062,-0.018208,0.036271,-0.023707,-0.024683,0.033225,-0.020288,-0.014740,0.040576,-0.019045,-0.021486,0.038090,-0.015037,-0.010925,0.043929,-0.013781,-0.017661,0.042111,-0.009692,-0.007041,0.046170,-0.008306,-0.013494,0.044990,-0.003028,-0.009319,0.046682,-0.021746,-0.030718,0.029304,-0.017258,-0.028037,0.034516,-0.015024,-0.033862,0.030048,-0.012085,-0.024487,0.039109,-0.010021,-0.030841,0.034980,-0.007749,-0.036226,0.030048,-0.006592,-0.020287,0.042664,-0.004616,-0.026914,0.039109,-0.002518,-0.032826,0.034516,-0.000463,-0.037634,0.029304,-0.001212,-0.015799,0.044990,0.000768,-0.022389,0.042111,0.002778,-0.028577,0.038090,0.004670,-0.033904,0.033225,0.006329,-0.038118,0.027968,0.003702,-0.011393,0.046170,0.005744,-0.017677,0.043929,0.007749,-0.023849,0.040576,0.009573,-0.029462,0.036271,0.011105,-0.034179,0.031363,0.012303,-0.037866,0.026267,0.017285,-0.034558,0.027968,0.016149,-0.030174,0.033225,0.014549,-0.024752,0.038090,0.012538,-0.018564,0.042111,0.010267,-0.012070,0.044990,0.007928,-0.005760,0.046682,0.022495,-0.030174,0.029304,0.021332,-0.025077,0.034516,0.027562,-0.024752,0.030048,0.019554,-0.019061,0.039109,0.026235,-0.019061,0.034980,0.032058,-0.018564,0.030048,0.017258,-0.012538,0.042664,0.024171,-0.012707,0.039109,0.030441,-0.012538,0.034516,0.035649,-0.012070,0.029304,0.014652,-0.006035,0.044990,0.021530,-0.006188,0.042111,0.028037,-0.006188,0.038090,0.033688,-0.006035,0.033225,0.038208,-0.005760,0.027967,0.011980,0.000000,0.046170,0.018587,0.000000,0.043929,0.025077,0.000000,0.040575,0.030979,0.000000,0.036270,0.035939,0.000000,0.031363,0.039815,0.000000,0.026267,0.038208,0.005760,0.027967,0.033688,0.006035,0.033225,0.028037,0.006188,0.038090,0.021530,0.006188,0.042111,0.014652,0.006035,0.044990,0.007928,0.005760,0.046682,0.035649,0.012070,0.029304,0.030441,0.012538,0.034516,0.032058,0.018564,0.030048,0.024171,0.012707,0.039109,0.026235,0.019061,0.034980,0.027562,0.024752,0.030048,0.017258,0.012538,0.042663,0.019554,0.019061,0.039109,0.021332,0.025077,0.034516,0.022495,0.030174,0.029304,0.010267,0.012070,0.044990,0.012538,0.018564,0.042111,0.014549,0.024752,0.038090,0.016149,0.030174,0.033225,0.017285,0.034558,0.027968,0.003702,0.011393,0.046170,0.005744,0.017677,0.043929,0.007749,0.023849,0.040576,0.009573,0.029462,0.036271,0.011105,0.034179,0.031363,0.012303,0.037866,0.026267,-0.034296,-0.017798,0.027968,-0.035935,-0.011189,0.029304,-0.036847,-0.003824,0.030048,-0.036847,0.003824,0.030048,-0.035935,0.011189,0.029304,-0.034296,0.017798,0.027968,-0.030801,-0.014919,0.033225,-0.031997,-0.007749,0.034516,-0.026319,-0.011473,0.038090,-0.032428,0.000000,0.034980,-0.027023,-0.003927,0.039109,-0.021056,-0.007649,0.042111,-0.031997,0.007749,0.034516,-0.027024,0.003927,0.039109,-0.021332,0.000000,0.042664,-0.015401,-0.003730,0.044990,-0.030801,0.014919,0.033225,-0.026319,0.011473,0.038090,-0.021056,0.007649,0.042111,-0.015401,0.003730,0.044990,-0.009799,0.000000,0.046682,-0.029075,0.021124,0.031363,-0.025062,0.018208,0.036271,-0.020288,0.014740,0.040576,-0.015037,0.010925,0.043929,-0.009692,0.007041,0.046170,0.006329,0.038118,0.027968,0.004670,0.033904,0.033225,0.002778,0.028577,0.038090,0.000768,0.022389,0.042111,-0.001212,0.015799,0.044990,-0.003028,0.009319,0.046682,-0.000463,0.037634,0.029304,-0.002518,0.032826,0.034516,-0.007749,0.036226,0.030048,-0.004616,0.026914,0.039109,-0.010021,0.030841,0.034980,-0.015024,0.033862,0.030048,-0.006592,0.020287,0.042664,-0.012085,0.024487,0.039109,-0.017258,0.028037,0.034516,-0.021746,0.030718,0.029304,-0.008306,0.013494,0.044990,-0.013781,0.017661,0.042111,-0.019045,0.021486,0.038090,-0.023707,0.024683,0.033225,-0.027526,0.027118,0.027968};
const GLushort minball_indices[] = {0,1,2,3,4,5,0,6,1,0,7,6,0,8,7,3,9,4,10,11,12,13,14,15,16,17,18,19,20,21,3,22,9,10,23,11,13,24,14,16,25,17,19,26,20,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,42,46,47,45,48,49,47,50,51,49,52,53,51,54,40,53,55,42,44,46,46,44,56,45,46,48,48,46,57,46,56,57,57,56,58,47,48,50,50,48,59,48,57,59,59,57,60,57,58,60,60,58,61,49,50,52,52,50,62,50,59,62,62,59,63,59,60,63,63,60,64,60,61,64,64,61,65,51,52,54,54,52,66,52,62,66,66,62,67,62,63,67,67,63,68,63,64,68,68,64,69,64,65,69,69,65,70,53,54,55,55,54,71,54,66,71,71,66,72,66,67,72,72,67,73,67,68,73,73,68,74,68,69,74,74,69,75,69,70,75,75,70,37,40,55,41,41,55,76,55,71,76,76,71,77,71,72,77,77,72,78,72,73,78,78,73,79,73,74,79,79,74,80,74,75,80,80,75,81,75,37,81,81,37,36,44,43,82,56,44,83,58,56,84,61,58,85,65,61,86,70,65,87,37,70,88,44,82,83,83,82,89,56,83,84,84,83,90,83,89,90,90,89,91,58,84,85,85,84,92,84,90,92,92,90,93,90,91,93,93,91,94,61,85,86,86,85,95,85,92,95,95,92,96,92,93,96,96,93,97,93,94,97,97,94,98,65,86,87,87,86,99,86,95,99,99,95,100,95,96,100,100,96,101,96,97,101,101,97,102,97,98,102,102,98,103,70,87,88,88,87,104,87,99,104,104,99,105,99,100,105,105,100,106,100,101,106,106,101,107,101,102,107,107,102,108,102,103,108,108,103,34,37,88,38,38,88,109,88,104,109,109,104,110,104,105,110,110,105,111,105,106,111,111,106,112,106,107,112,112,107,113,107,108,113,113,108,114,108,34,114,114,34,33,82,43,115,89,82,116,91,89,117,94,91,118,98,94,119,103,98,120,34,103,121,82,115,116,116,115,122,89,116,117,117,116,123,116,122,123,123,122,124,91,117,118,118,117,125,117,123,125,125,123,126,123,124,126,126,124,127,94,118,119,119,118,128,118,125,128,128,125,129,125,126,129,129,126,130,126,127,130,130,127,131,98,119,120,120,119,132,119,128,132,132,128,133,128,129,133,133,129,134,129,130,134,134,130,135,130,131,135,135,131,136,103,120,121,121,120,137,120,132,137,137,132,138,132,133,138,138,133,139,133,134,139,139,134,140,134,135,140,140,135,141,135,136,141,141,136,31,34,121,35,35,121,142,121,137,142,142,137,143,137,138,143,143,138,144,138,139,144,144,139,145,139,140,145,145,140,146,140,141,146,146,141,147,141,31,147,147,31,30,115,43,148,122,115,149,124,122,150,127,124,151,131,127,152,136,131,153,31,136,154,115,148,149,149,148,155,122,149,150,150,149,156,149,155,156,156,155,157,124,150,151,151,150,158,150,156,158,158,156,159,156,157,159,159,157,160,127,151,152,152,151,161,151,158,161,161,158,162,158,159,162,162,159,163,159,160,163,163,160,164,131,152,153,153,152,165,152,161,165,165,161,166,161,162,166,166,162,167,162,163,167,167,163,168,163,164,168,168,164,169,136,153,154,154,153,170,153,165,170,170,165,171,165,166,171,171,166,172,166,167,172,172,167,173,167,168,173,173,168,174,168,169,174,174,169,28,31,154,32,32,154,175,154,170,175,175,170,176,170,171,176,176,171,177,171,172,177,177,172,178,172,173,178,178,173,179,173,174,179,179,174,180,174,28,180,180,28,27,148,43,42,155,148,181,157,155,182,160,157,183,164,160,184,169,164,185,28,169,186,148,42,181,181,42,45,155,181,182,182,181,187,181,45,187,187,45,47,157,182,183,183,182,188,182,187,188,188,187,189,187,47,189,189,47,49,160,183,184,184,183,190,183,188,190,190,188,191,188,189,191,191,189,192,189,49,192,192,49,51,164,184,185,185,184,193,184,190,193,193,190,194,190,191,194,194,191,195,191,192,195,195,192,196,192,51,196,196,51,53,169,185,186,186,185,197,185,193,197,197,193,198,193,194,198,198,194,199,194,195,199,199,195,200,195,196,200,200,196,201,196,53,201,201,53,40,28,186,29,29,186,202,186,197,202,202,197,203,197,198,203,203,198,204,198,199,204,204,199,205,199,200,205,205,200,206,200,201,206,206,201,207,201,40,207,207,40,39,208,39,41,209,208,210,211,209,212,213,211,214,215,213,216,217,215,218,26,217,219,208,41,210,210,41,76,209,210,212,212,210,220,210,76,220,220,76,77,211,212,214,214,212,221,212,220,221,221,220,222,220,77,222,222,77,78,213,214,216,216,214,223,214,221,223,223,221,224,221,222,224,224,222,225,222,78,225,225,78,79,215,216,218,218,216,226,216,223,226,226,223,227,223,224,227,227,224,228,224,225,228,228,225,229,225,79,229,229,79,80,217,218,219,219,218,230,218,226,230,230,226,231,226,227,231,231,227,232,227,228,232,232,228,233,228,229,233,233,229,234,229,80,234,234,80,81,26,219,20,20,219,235,219,230,235,235,230,236,230,231,236,236,231,237,231,232,237,237,232,238,232,233,238,238,233,239,233,234,239,239,234,240,234,81,240,240,81,36,241,36,38,242,241,243,244,242,245,246,244,247,248,246,249,250,248,251,25,250,252,241,38,243,243,38,109,242,243,245,245,243,253,243,109,253,253,109,110,244,245,247,247,245,254,245,253,254,254,253,255,253,110,255,255,110,111,246,247,249,249,247,256,247,254,256,256,254,257,254,255,257,257,255,258,255,111,258,258,111,112,248,249,251,251,249,259,249,256,259,259,256,260,256,257,260,260,257,261,257,258,261,261,258,262,258,112,262,262,112,113,250,251,252,252,251,263,251,259,263,263,259,264,259,260,264,264,260,265,260,261,265,265,261,266,261,262,266,266,262,267,262,113,267,267,113,114,25,252,17,17,252,268,252,263,268,268,263,269,263,264,269,269,264,270,264,265,270,270,265,271,265,266,271,271,266,272,266,267,272,272,267,273,267,114,273,273,114,33,274,33,35,275,274,276,277,275,278,279,277,280,281,279,282,283,281,284,24,283,285,274,35,276,276,35,142,275,276,278,278,276,286,276,142,286,286,142,143,277,278,280,280,278,287,278,286,287,287,286,288,286,143,288,288,143,144,279,280,282,282,280,289,280,287,289,289,287,290,287,288,290,290,288,291,288,144,291,291,144,145,281,282,284,284,282,292,282,289,292,292,289,293,289,290,293,293,290,294,290,291,294,294,291,295,291,145,295,295,145,146,283,284,285,285,284,296,284,292,296,296,292,297,292,293,297,297,293,298,293,294,298,298,294,299,294,295,299,299,295,300,295,146,300,300,146,147,24,285,14,14,285,301,285,296,301,301,296,302,296,297,302,302,297,303,297,298,303,303,298,304,298,299,304,304,299,305,299,300,305,305,300,306,300,147,306,306,147,30,307,30,32,308,307,309,310,308,311,312,310,313,314,312,315,316,314,317,23,316,318,307,32,309,309,32,175,308,309,311,311,309,319,309,175,319,319,175,176,310,311,313,313,311,320,311,319,320,320,319,321,319,176,321,321,176,177,312,313,315,315,313,322,313,320,322,322,320,323,320,321,323,323,321,324,321,177,324,324,177,178,314,315,317,317,315,325,315,322,325,325,322,326,322,323,326,326,323,327,323,324,327,327,324,328,324,178,328,328,178,179,316,317,318,318,317,329,317,325,329,329,325,330,325,326,330,330,326,331,326,327,331,331,327,332,327,328,332,332,328,333,328,179,333,333,179,180,23,318,11,11,318,334,318,329,334,334,329,335,329,330,335,335,330,336,330,331,336,336,331,337,331,332,337,337,332,338,332,333,338,338,333,339,333,180,339,339,180,27,340,27,29,341,340,342,343,341,344,345,343,346,347,345,348,349,347,350,22,349,351,340,29,342,342,29,202,341,342,344,344,342,352,342,202,352,352,202,203,343,344,346,346,344,353,344,352,353,353,352,354,352,203,354,354,203,204,345,346,348,348,346,355,346,353,355,355,353,356,353,354,356,356,354,357,354,204,357,357,204,205,347,348,350,350,348,358,348,355,358,358,355,359,355,356,359,359,356,360,356,357,360,360,357,361,357,205,361,361,205,206,349,350,351,351,350,362,350,358,362,362,358,363,358,359,363,363,359,364,359,360,364,364,360,365,360,361,365,365,361,366,361,206,366,366,206,207,22,351,9,9,351,367,351,362,367,367,362,368,362,363,368,368,363,369,363,364,369,369,364,370,364,365,370,370,365,371,365,366,371,371,366,372,366,207,372,372,207,39,240,36,241,239,240,373,238,239,374,237,238,375,236,237,376,235,236,377,20,235,378,240,241,373,373,241,242,239,373,374,374,373,379,373,242,379,379,242,244,238,374,375,375,374,380,374,379,380,380,379,381,379,244,381,381,244,246,237,375,376,376,375,382,375,380,382,382,380,383,380,381,383,383,381,384,381,246,384,384,246,248,236,376,377,377,376,385,376,382,385,385,382,386,382,383,386,386,383,387,383,384,387,387,384,388,384,248,388,388,248,250,235,377,378,378,377,389,377,385,389,389,385,390,385,386,390,390,386,391,386,387,391,391,387,392,387,388,392,392,388,393,388,250,393,393,250,25,20,378,21,21,378,394,378,389,394,394,389,395,389,390,395,395,390,396,390,391,396,396,391,397,391,392,397,397,392,398,392,393,398,398,393,399,393,25,399,399,25,16,273,33,274,272,273,400,271,272,401,270,271,402,269,270,403,268,269,404,17,268,405,273,274,400,400,274,275,272,400,401,401,400,406,400,275,406,406,275,277,271,401,402,402,401,407,401,406,407,407,406,408,406,277,408,408,277,279,270,402,403,403,402,409,402,407,409,409,407,410,407,408,410,410,408,411,408,279,411,411,279,281,269,403,404,404,403,412,403,409,412,412,409,413,409,410,413,413,410,414,410,411,414,414,411,415,411,281,415,415,281,283,268,404,405,405,404,416,404,412,416,416,412,417,412,413,417,417,413,418,413,414,418,418,414,419,414,415,419,419,415,420,415,283,420,420,283,24,17,405,18,18,405,421,405,416,421,421,416,422,416,417,422,422,417,423,417,418,423,423,418,424,418,419,424,424,419,425,419,420,425,425,420,426,420,24,426,426,24,13,306,30,307,305,306,427,304,305,428,303,304,429,302,303,430,301,302,431,14,301,432,306,307,427,427,307,308,305,427,428,428,427,433,427,308,433,433,308,310,304,428,429,429,428,434,428,433,434,434,433,435,433,310,435,435,310,312,303,429,430,430,429,436,429,434,436,436,434,437,434,435,437,437,435,438,435,312,438,438,312,314,302,430,431,431,430,439,430,436,439,439,436,440,436,437,440,440,437,441,437,438,441,441,438,442,438,314,442,442,314,316,301,431,432,432,431,443,431,439,443,443,439,444,439,440,444,444,440,445,440,441,445,445,441,446,441,442,446,446,442,447,442,316,447,447,316,23,14,432,15,15,432,448,432,443,448,448,443,449,443,444,449,449,444,450,444,445,450,450,445,451,445,446,451,451,446,452,446,447,452,452,447,453,447,23,453,453,23,10,339,27,340,338,339,454,337,338,455,336,337,456,335,336,457,334,335,458,11,334,459,339,340,454,454,340,341,338,454,455,455,454,460,454,341,460,460,341,343,337,455,456,456,455,461,455,460,461,461,460,462,460,343,462,462,343,345,336,456,457,457,456,463,456,461,463,463,461,464,461,462,464,464,462,465,462,345,465,465,345,347,335,457,458,458,457,466,457,463,466,466,463,467,463,464,467,467,464,468,464,465,468,468,465,469,465,347,469,469,347,349,334,458,459,459,458,470,458,466,470,470,466,471,466,467,471,471,467,472,467,468,472,472,468,473,468,469,473,473,469,474,469,349,474,474,349,22,11,459,12,12,459,475,459,470,475,475,470,476,470,471,476,476,471,477,471,472,477,477,472,478,472,473,478,478,473,479,473,474,479,479,474,480,474,22,480,480,22,3,372,39,208,371,372,481,370,371,482,369,370,483,368,369,484,367,368,485,9,367,486,372,208,481,481,208,209,371,481,482,482,481,487,481,209,487,487,209,211,370,482,483,483,482,488,482,487,488,488,487,489,487,211,489,489,211,213,369,483,484,484,483,490,483,488,490,490,488,491,488,489,491,491,489,492,489,213,492,492,213,215,368,484,485,485,484,493,484,490,493,493,490,494,490,491,494,494,491,495,491,492,495,495,492,496,492,215,496,496,215,217,367,485,486,486,485,497,485,493,497,497,493,498,493,494,498,498,494,499,494,495,499,499,495,500,495,496,500,500,496,501,496,217,501,501,217,26,9,486,4,4,486,502,486,497,502,502,497,503,497,498,503,503,498,504,498,499,504,504,499,505,499,500,505,505,500,506,500,501,506,506,501,507,501,26,507,507,26,19,508,19,21,509,508,510,511,509,512,513,511,514,515,513,516,517,515,518,8,517,519,508,21,510,510,21,394,509,510,512,512,510,520,510,394,520,520,394,395,511,512,514,514,512,521,512,520,521,521,520,522,520,395,522,522,395,396,513,514,516,516,514,523,514,521,523,523,521,524,521,522,524,524,522,525,522,396,525,525,396,397,515,516,518,518,516,526,516,523,526,526,523,527,523,524,527,527,524,528,524,525,528,528,525,529,525,397,529,529,397,398,517,518,519,519,518,530,518,526,530,530,526,531,526,527,531,531,527,532,527,528,532,532,528,533,528,529,533,533,529,534,529,398,534,534,398,399,8,519,7,7,519,535,519,530,535,535,530,536,530,531,536,536,531,537,531,532,537,537,532,538,532,533,538,538,533,539,533,534,539,539,534,540,534,399,540,540,399,16,540,16,18,539,540,541,538,539,542,537,538,543,536,537,544,535,536,545,7,535,546,540,18,541,541,18,421,539,541,542,542,541,547,541,421,547,547,421,422,538,542,543,543,542,548,542,547,548,548,547,549,547,422,549,549,422,423,537,543,544,544,543,550,543,548,550,550,548,551,548,549,551,551,549,552,549,423,552,552,423,424,536,544,545,545,544,553,544,550,553,553,550,554,550,551,554,554,551,555,551,552,555,555,552,556,552,424,556,556,424,425,535,545,546,546,545,557,545,553,557,557,553,558,553,554,558,558,554,559,554,555,559,559,555,560,555,556,560,560,556,561,556,425,561,561,425,426,7,546,6,6,546,562,546,557,562,562,557,563,557,558,563,563,558,564,558,559,564,564,559,565,559,560,565,565,560,566,560,561,566,566,561,567,561,426,567,567,426,13,567,13,15,566,567,568,565,566,569,564,565,570,563,564,571,562,563,572,6,562,573,567,15,568,568,15,448,566,568,569,569,568,574,568,448,574,574,448,449,565,569,570,570,569,575,569,574,575,575,574,576,574,449,576,576,449,450,564,570,571,571,570,577,570,575,577,577,575,578,575,576,578,578,576,579,576,450,579,579,450,451,563,571,572,572,571,580,571,577,580,580,577,581,577,578,581,581,578,582,578,579,582,582,579,583,579,451,583,583,451,452,562,572,573,573,572,584,572,580,584,584,580,585,580,581,585,585,581,586,581,582,586,586,582,587,582,583,587,587,583,588,583,452,588,588,452,453,6,573,1,1,573,589,573,584,589,589,584,590,584,585,590,590,585,591,585,586,591,591,586,592,586,587,592,592,587,593,587,588,593,593,588,594,588,453,594,594,453,10,507,19,508,506,507,595,505,506,596,504,505,597,503,504,598,502,503,599,4,502,600,507,508,595,595,508,509,506,595,596,596,595,601,595,509,601,601,509,511,505,596,597,597,596,602,596,601,602,602,601,603,601,511,603,603,511,513,504,597,598,598,597,604,597,602,604,604,602,605,602,603,605,605,603,606,603,513,606,606,513,515,503,598,599,599,598,607,598,604,607,607,604,608,604,605,608,608,605,609,605,606,609,609,606,610,606,515,610,610,515,517,502,599,600,600,599,611,599,607,611,611,607,612,607,608,612,612,608,613,608,609,613,613,609,614,609,610,614,614,610,615,610,517,615,615,517,8,4,600,5,5,600,616,600,611,616,616,611,617,611,612,617,617,612,618,612,613,618,618,613,619,613,614,619,619,614,620,614,615,620,620,615,2,615,8,2,2,8,0,594,10,12,593,594,621,592,593,622,591,592,623,590,591,624,589,590,625,1,589,626,594,12,621,621,12,475,593,621,622,622,621,627,621,475,627,627,475,476,592,622,623,623,622,628,622,627,628,628,627,629,627,476,629,629,476,477,591,623,624,624,623,630,623,628,630,630,628,631,628,629,631,631,629,632,629,477,632,632,477,478,590,624,625,625,624,633,624,630,633,633,630,634,630,631,634,634,631,635,631,632,635,635,632,636,632,478,636,636,478,479,589,625,626,626,625,637,625,633,637,637,633,638,633,634,638,638,634,639,634,635,639,639,635,640,635,636,640,640,636,641,636,479,641,641,479,480,1,626,2,2,626,620,626,637,620,620,637,619,637,638,619,619,638,618,638,639,618,618,639,617,639,640,617,617,640,616,640,641,616,616,641,5,641,480,5,5,480,3};
const GLsizeiptr minball_numind = 3840;
const GLsizeiptr minball_numvert = 642;

#endif
