-- DB update 2022_10_15_02 -> 2022_10_15_03
-- Eversong Woods
UPDATE `gameobject` SET `ZoneId`=3430 WHERE `guid` IN (1268,1269,1270,1271,1272,1273,1274,1275,1276,1277,1278,1279,1280,1281,1282,1283,1284,1285,1286,1287,1288,1289,1290,1292,1293,1294,1308,1309,1310,1311,1312,1313,1314,1315,1316,1317,1318,1319,1320,1321,1322,1323,1324,1325,1326,1327,1328,1872,1873,1874,1875,1876,1877,1878,1879,1880,1881,21297,21298,21299,21300,21301,21302,21303,21304,21305,21306,21307,21308,21309,21310,21311,21312,21313,21314,21315,21316,21317,21318,21319,21320,33888,33889,33893,33896,33897,33900,33901,33908,33909,33910,33912,33914,33915,33916,33917,33918,33927,33930,33931,33933,33935,33936,33937,33938,33939,33940,33941,33942,33943,33944,33946,33949,33950,33952,33954,33955,64924,64925,64926,64927,64929,64935,64937,64938,64939,64940,64947,64948,64958,64959,64960,64961,64962,64963,64969,64970,64971,64977,64978,64992,64993,64994,64996,64997,64998,65124,65125,65126,65127,65128,65129,65130,65131,65132,65133,65134,65135,87202);

-- Duskwither Grounds:
UPDATE `gameobject` SET `AreaId`=3480 WHERE `guid` IN (33942, 65126, 33946, 21309, 21306, 65125, 33940, 65124, 33939, 21307, 33937, 21308, 21305, 33938, 21304);

-- Stillwhisper Pond
UPDATE `gameobject` SET `AreaId`=3470 WHERE `guid` IN (33908, 21303);

-- Saltheril's Haven
UPDATE `gameobject` SET `AreaId`=3468 WHERE `guid` IN (65134);

-- North Sanctum
UPDATE `gameobject` SET `AreaId`=3465 WHERE `guid` IN (21302, 21301, 21297, 65127);

-- West Sanctum
UPDATE `gameobject` SET `AreaId`=3466 WHERE `guid` IN (65128, 21298, 21300, 33931, 21299);

-- The Scorched Grove
UPDATE `gameobject` SET `AreaId`=3474 WHERE `guid` IN (65132, 21310, 21311, 65129);

-- Runestone Falithas
UPDATE `gameobject` SET `AreaId`=3913 WHERE `guid` IN (21312, 65130, 21313, 65131);

-- Runestone Shan'dor
UPDATE `gameobject` SET `AreaId`=3914 WHERE `guid` IN (21320, 21318, 21319, 65133);

-- East Sanctum
UPDATE `gameobject` SET `AreaId`=3467 WHERE `guid` IN (21316, 33900, 33896, 21314, 65135, 33897, 21317, 21315);

DELETE FROM `pool_template` WHERE `entry`=970;
DELETE FROM `pool_gameobject` WHERE `pool_entry`=970;

DELETE FROM `pool_template` WHERE `entry` BETWEEN 717 AND 727;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(717, 25, 'Peacebloom in Eversong Woods'),
(718, 25, 'Silverleaf in Eversong Woods'),
(719, 15, 'Earthroot in Eversong Woods'),
(720, 3, 'Bloodthistle in West Sanctum'),
(721, 2, 'Bloodthistle in The Scorched Grove'),
(722, 3, 'Bloodthistle in Runestone Falithas'),
(723, 2, 'Bloodthistle in Runestone Shan\'dor'),
(724, 3, 'Bloodthistle in East Sanctum'),
(725, 1, 'Bloodthistle in Stillwhisper Pond/Saltheril\'s Haven'),
(726, 3, 'Bloodthistle in North Sanctum'),
(727, 6, 'Bloodthistle in Duskwither Grounds');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 717 AND 727;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(1308, 717, 0, 'Peacebloom'),
(1309, 717, 0, 'Peacebloom'),
(1310, 717, 0, 'Peacebloom'),
(1311, 717, 0, 'Peacebloom'),
(1312, 717, 0, 'Peacebloom'),
(1313, 717, 0, 'Peacebloom'),
(1314, 717, 0, 'Peacebloom'),
(1315, 717, 0, 'Peacebloom'),
(1316, 717, 0, 'Peacebloom'),
(1317, 717, 0, 'Peacebloom'),
(1318, 717, 0, 'Peacebloom'),
(1319, 717, 0, 'Peacebloom'),
(1320, 717, 0, 'Peacebloom'),
(1321, 717, 0, 'Peacebloom'),
(1322, 717, 0, 'Peacebloom'),
(1323, 717, 0, 'Peacebloom'),
(1324, 717, 0, 'Peacebloom'),
(1325, 717, 0, 'Peacebloom'),
(1326, 717, 0, 'Peacebloom'),
(1327, 717, 0, 'Peacebloom'),
(1328, 717, 0, 'Peacebloom'),
(33889, 717, 0, 'Peacebloom'),
(33893, 717, 0, 'Peacebloom'),
(33910, 717, 0, 'Peacebloom'),
(33912, 717, 0, 'Peacebloom'),
(33914, 717, 0, 'Peacebloom'),
(33930, 717, 0, 'Peacebloom'),
(33933, 717, 0, 'Peacebloom'),
(33935, 717, 0, 'Peacebloom'),
(33943, 717, 0, 'Peacebloom'),
(33954, 717, 0, 'Peacebloom'),
(64947, 717, 0, 'Peacebloom'),
(64948, 717, 0, 'Peacebloom'),
(64958, 717, 0, 'Peacebloom'),
(64959, 717, 0, 'Peacebloom'),
(64960, 717, 0, 'Peacebloom'),
(64961, 717, 0, 'Peacebloom'),
(64962, 717, 0, 'Peacebloom'),
(64963, 717, 0, 'Peacebloom'),
(64969, 717, 0, 'Peacebloom'),
(64970, 717, 0, 'Peacebloom'),
(64971, 717, 0, 'Peacebloom'),

(1268, 718, 0, 'Silverleaf'),
(1269, 718, 0, 'Silverleaf'),
(1270, 718, 0, 'Silverleaf'),
(1271, 718, 0, 'Silverleaf'),
(1272, 718, 0, 'Silverleaf'),
(1273, 718, 0, 'Silverleaf'),
(1274, 718, 0, 'Silverleaf'),
(1275, 718, 0, 'Silverleaf'),
(1276, 718, 0, 'Silverleaf'),
(1277, 718, 0, 'Silverleaf'),
(1278, 718, 0, 'Silverleaf'),
(1279, 718, 0, 'Silverleaf'),
(1280, 718, 0, 'Silverleaf'),
(1281, 718, 0, 'Silverleaf'),
(1282, 718, 0, 'Silverleaf'),
(1283, 718, 0, 'Silverleaf'),
(1284, 718, 0, 'Silverleaf'),
(1285, 718, 0, 'Silverleaf'),
(1286, 718, 0, 'Silverleaf'),
(1287, 718, 0, 'Silverleaf'),
(1288, 718, 0, 'Silverleaf'),
(1289, 718, 0, 'Silverleaf'),
(1290, 718, 0, 'Silverleaf'),
(1292, 718, 0, 'Silverleaf'),
(1293, 718, 0, 'Silverleaf'),
(1294, 718, 0, 'Silverleaf'),
(33888, 718, 0, 'Silverleaf'),
(33909, 718, 0, 'Silverleaf'),
(33915, 718, 0, 'Silverleaf'),
(33916, 718, 0, 'Silverleaf'),
(33917, 718, 0, 'Silverleaf'),
(33918, 718, 0, 'Silverleaf'),
(33936, 718, 0, 'Silverleaf'),
(33941, 718, 0, 'Silverleaf'),
(33944, 718, 0, 'Silverleaf'),
(33950, 718, 0, 'Silverleaf'),
(33952, 718, 0, 'Silverleaf'),
(33955, 718, 0, 'Silverleaf'),
(64924, 718, 0, 'Silverleaf'),
(64925, 718, 0, 'Silverleaf'),
(64926, 718, 0, 'Silverleaf'),
(64927, 718, 0, 'Silverleaf'),
(64929, 718, 0, 'Silverleaf'),
(64935, 718, 0, 'Silverleaf'),
(64937, 718, 0, 'Silverleaf'),
(64938, 718, 0, 'Silverleaf'),
(64939, 718, 0, 'Silverleaf'),
(64940, 718, 0, 'Silverleaf'),
(87202, 718, 0, 'Silverleaf'),

(1872, 719, 0, 'Earthroot'),
(1873, 719, 0, 'Earthroot'),
(1874, 719, 0, 'Earthroot'),
(1875, 719, 0, 'Earthroot'),
(1876, 719, 0, 'Earthroot'),
(1877, 719, 0, 'Earthroot'),
(1878, 719, 0, 'Earthroot'),
(1879, 719, 0, 'Earthroot'),
(1880, 719, 0, 'Earthroot'),
(1881, 719, 0, 'Earthroot'),
(33901, 719, 0, 'Earthroot'),
(33927, 719, 0, 'Earthroot'),
(33949, 719, 0, 'Earthroot'),
(64977, 719, 0, 'Earthroot'),
(64978, 719, 0, 'Earthroot'),
(64992, 719, 0, 'Earthroot'),
(64993, 719, 0, 'Earthroot'),
(64994, 719, 0, 'Earthroot'),
(64996, 719, 0, 'Earthroot'),
(64997, 719, 0, 'Earthroot'),
(64998, 719, 0, 'Earthroot'),

(21298, 720, 0, 'Bloodthistle'),
(21299, 720, 0, 'Bloodthistle'),
(21300, 720, 0, 'Bloodthistle'),
(33931, 720, 0, 'Bloodthistle'),
(65128, 720, 0, 'Bloodthistle'),

(21310, 721, 0, 'Bloodthistle'),
(21311, 721, 0, 'Bloodthistle'),
(65129, 721, 0, 'Bloodthistle'),
(65132, 721, 0, 'Bloodthistle'),

(21312, 722, 0, 'Bloodthistle'),
(21313, 722, 0, 'Bloodthistle'),
(65130, 722, 0, 'Bloodthistle'),
(65131, 722, 0, 'Bloodthistle'),

(21318, 723, 0, 'Bloodthistle'),
(21319, 723, 0, 'Bloodthistle'),
(21320, 723, 0, 'Bloodthistle'),
(65133, 723, 0, 'Bloodthistle'),

(21314, 724, 0, 'Bloodthistle'),
(21315, 724, 0, 'Bloodthistle'),
(21316, 724, 0, 'Bloodthistle'),
(21317, 724, 0, 'Bloodthistle'),
(33896, 724, 0, 'Bloodthistle'),
(33897, 724, 0, 'Bloodthistle'),
(33900, 724, 0, 'Bloodthistle'),
(65135, 724, 0, 'Bloodthistle'),

(21303, 725, 0, 'Bloodthistle'),
(33908, 725, 0, 'Bloodthistle'),
(65134, 725, 0, 'Bloodthistle'),

(21297, 726, 0, 'Bloodthistle'),
(21301, 726, 0, 'Bloodthistle'),
(21302, 726, 0, 'Bloodthistle'),
(65127, 726, 0, 'Bloodthistle'),

(21304, 727, 0, 'Bloodthistle'),
(21305, 727, 0, 'Bloodthistle'),
(21306, 727, 0, 'Bloodthistle'),
(21307, 727, 0, 'Bloodthistle'),
(21308, 727, 0, 'Bloodthistle'),
(21309, 727, 0, 'Bloodthistle'),
(33937, 727, 0, 'Bloodthistle'),
(33938, 727, 0, 'Bloodthistle'),
(33939, 727, 0, 'Bloodthistle'),
(33940, 727, 0, 'Bloodthistle'),
(33942, 727, 0, 'Bloodthistle'),
(33946, 727, 0, 'Bloodthistle'),
(65124, 727, 0, 'Bloodthistle'),
(65125, 727, 0, 'Bloodthistle'),
(65126, 727, 0, 'Bloodthistle');

-- Azuremyst Isle
UPDATE `gameobject` SET `ZoneId`=3524 WHERE `guid` IN (1295,1296,1297,1298,1299,1300,1301,1302,1303,1304,1305,1306,1307,1329,1330,1331,1332,1333,1334,1335,1336,1337,1338,1339,1340,1341,1342,1343,1344,1882,1883,1884,1885,1886,1887,1888,1889,1890,1891,1892,1893,1894,30446,30447,30454,30461,30464,30469,30471,30477,30480,30482,30495,30499,30500,30501,30506,30518,30526,30527,30530,30532,39946,39947,85302,85303,85304,85305,85306,85308,85309,85310,85311,85312,85313,85314,85315,85316,85317,85318,85319,85320,85321,85323,85324,85325,85326,85329,85332,85333,85338,85348,85352,85356,85364,85369,85372,85387,85388,86161,86173,86180,86191,86193,86194,86197,86218,86221,86242,86243,86244,87059);

DELETE FROM `pool_template` WHERE `entry`=971;
DELETE FROM `pool_gameobject` WHERE `pool_entry`=971;

DELETE FROM `pool_template` WHERE `entry` BETWEEN 728 AND 730;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(728, 23, 'Peacebloom in Azuremyst Isle'),
(729, 23, 'Silverleaf in Azuremyst Isle'),
(730, 12, 'Earthroot in Azuremyst Isle');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 728 AND 730;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(85387, 730, 0, 'Earthroot'),
(85388, 730, 0, 'Earthroot'),
(86221, 730, 0, 'Earthroot'),
(86242, 730, 0, 'Earthroot'),
(86243, 730, 0, 'Earthroot'),
(86244, 730, 0, 'Earthroot'),
(87059, 730, 0, 'Earthroot'),
(1882, 730, 0, 'Earthroot'),
(1883, 730, 0, 'Earthroot'),
(1884, 730, 0, 'Earthroot'),
(1885, 730, 0, 'Earthroot'),
(1886, 730, 0, 'Earthroot'),
(1891, 730, 0, 'Earthroot'),
(1892, 730, 0, 'Earthroot'),
(1893, 730, 0, 'Earthroot'),
(1894, 730, 0, 'Earthroot'),
(30471, 730, 0, 'Earthroot'),
(30527, 730, 0, 'Earthroot'),
(85320, 730, 0, 'Earthroot'),
(85321, 730, 0, 'Earthroot'),
(85323, 730, 0, 'Earthroot'),
(85324, 730, 0, 'Earthroot'),
(85326, 730, 0, 'Earthroot'),

(86197, 728, 0, 'Peacebloom'),
(86218, 728, 0, 'Peacebloom'),
(1329, 728, 0, 'Peacebloom'),
(1330, 728, 0, 'Peacebloom'),
(1331, 728, 0, 'Peacebloom'),
(1332, 728, 0, 'Peacebloom'),
(1333, 728, 0, 'Peacebloom'),
(1334, 728, 0, 'Peacebloom'),
(1335, 728, 0, 'Peacebloom'),
(1336, 728, 0, 'Peacebloom'),
(1337, 728, 0, 'Peacebloom'),
(1342, 728, 0, 'Peacebloom'),
(1343, 728, 0, 'Peacebloom'),
(1344, 728, 0, 'Peacebloom'),
(30447, 728, 0, 'Peacebloom'),
(30454, 728, 0, 'Peacebloom'),
(30464, 728, 0, 'Peacebloom'),
(30480, 728, 0, 'Peacebloom'),
(30495, 728, 0, 'Peacebloom'),
(30500, 728, 0, 'Peacebloom'),
(30506, 728, 0, 'Peacebloom'),
(30530, 728, 0, 'Peacebloom'),
(30532, 728, 0, 'Peacebloom'),
(85312, 728, 0, 'Peacebloom'),
(85313, 728, 0, 'Peacebloom'),
(85314, 728, 0, 'Peacebloom'),
(85315, 728, 0, 'Peacebloom'),
(85316, 728, 0, 'Peacebloom'),
(85317, 728, 0, 'Peacebloom'),
(85318, 728, 0, 'Peacebloom'),
(85364, 728, 0, 'Peacebloom'),
(85369, 728, 0, 'Peacebloom'),
(85372, 728, 0, 'Peacebloom'),

(1295, 729, 0, 'Silverleaf'),
(86161, 729, 0, 'Silverleaf'),
(86173, 729, 0, 'Silverleaf'),
(86180, 729, 0, 'Silverleaf'),
(86191, 729, 0, 'Silverleaf'),
(86193, 729, 0, 'Silverleaf'),
(86194, 729, 0, 'Silverleaf'),
(1305, 729, 0, 'Silverleaf'),
(1306, 729, 0, 'Silverleaf'),
(1307, 729, 0, 'Silverleaf'),
(1296, 729, 0, 'Silverleaf'),
(1297, 729, 0, 'Silverleaf'),
(1298, 729, 0, 'Silverleaf'),
(30446, 729, 0, 'Silverleaf'),
(30461, 729, 0, 'Silverleaf'),
(30469, 729, 0, 'Silverleaf'),
(1299, 729, 0, 'Silverleaf'),
(30477, 729, 0, 'Silverleaf'),
(30482, 729, 0, 'Silverleaf'),
(30499, 729, 0, 'Silverleaf'),
(30501, 729, 0, 'Silverleaf'),
(30518, 729, 0, 'Silverleaf'),
(1300, 729, 0, 'Silverleaf'),
(30526, 729, 0, 'Silverleaf'),
(39946, 729, 0, 'Silverleaf'),
(39947, 729, 0, 'Silverleaf'),
(85302, 729, 0, 'Silverleaf'),
(85303, 729, 0, 'Silverleaf'),
(85304, 729, 0, 'Silverleaf'),
(85305, 729, 0, 'Silverleaf'),
(1301, 729, 0, 'Silverleaf'),
(85306, 729, 0, 'Silverleaf'),
(85308, 729, 0, 'Silverleaf'),
(85309, 729, 0, 'Silverleaf'),
(85310, 729, 0, 'Silverleaf'),
(1302, 729, 0, 'Silverleaf'),
(85329, 729, 0, 'Silverleaf'),
(85332, 729, 0, 'Silverleaf'),
(85333, 729, 0, 'Silverleaf'),
(85338, 729, 0, 'Silverleaf'),
(85348, 729, 0, 'Silverleaf'),
(85352, 729, 0, 'Silverleaf'),
(85356, 729, 0, 'Silverleaf');

-- Silvermyst Isle, it's the isle southwest of Azuremyst
DELETE FROM `pool_template` WHERE `entry` BETWEEN 731 AND 733;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(731, 2, 'Peacebloom in Silvermyst Isle'),
(732, 2, 'Silverleaf in Silvermyst Isle'),
(733, 3, 'Earthroot in Silvermyst Isle');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 731 AND 733;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(1338, 731, 0, 'Peacebloom'),
(1339, 731, 0, 'Peacebloom'),
(1340, 731, 0, 'Peacebloom'),
(1341, 731, 0, 'Peacebloom'),

(1303, 732, 0, 'Silverleaf'),
(1304, 732, 0, 'Silverleaf'),
(85311, 732, 0, 'Silverleaf'),

(85325, 733, 0, 'Earthroot'),
(1887, 733, 0, 'Earthroot'),
(1888, 733, 0, 'Earthroot'),
(1889, 733, 0, 'Earthroot'),
(1890, 733, 0, 'Earthroot'),
(85319, 733, 0, 'Earthroot');

-- Ghostlands Old Pool 969
UPDATE `gameobject` SET `ZoneId`=3433 WHERE `guid` IN (1291,27209,27233,27237,27242,27253,27269,27270,27271,27273,27275,27294,27300,27302,27303,27308,27309,27310,27323,27369,27380,27386,27387,27390,27423,27426,27427,27430,27433,27434,27440,27450,27451,27456,27457,27458,27459,27460,27461,27466,27468,27491,27492,27494,27495,27496,27513,27526,27527,27528,27529,27531,27535,27537,27538,27539,27540,33289,33295,33296,33297,33298,33299,33885,33956,33957,33958,33960,33961,33962,33963,33965,33973,33975,33978,33982,33983,33985,33986,33988,33990,33991,33993,33994,33995,33996,34005,34013,34014,34015,34021,34022,64908,64918,64923,64928,64931,64933,64934,64936,64949,64950,64965,64966,64967,64968,64984,64991,64995,65006,65015,65021,65024,65025,65045,65064);

DELETE FROM `pool_template` WHERE `entry`=969;
DELETE FROM `pool_gameobject` WHERE `pool_entry`=969;

DELETE FROM `pool_template` WHERE `entry` BETWEEN 734 AND 740;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(734, 22, 'Silverleaf in Ghostlands'),
(735, 14, 'Peacebloom in Ghostlands'),
(736, 11, 'Earthroot in Ghostlands'),
(737, 8, 'Mageroyal in Ghostlands'),
(738, 8, 'Briarthorn in Ghostlands'),
(739, 6, 'Stranglekelp in Ghostlands'),
(740, 6, 'Bruiseweed in Ghostlands');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 734 AND 740;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(1291, 734, 0, 'Silverleaf'),
(64936, 734, 0, 'Silverleaf'),
(27300, 734, 0, 'Silverleaf'),
(27303, 734, 0, 'Silverleaf'),
(27369, 734, 0, 'Silverleaf'),
(27380, 734, 0, 'Silverleaf'),
(27390, 734, 0, 'Silverleaf'),
(27423, 734, 0, 'Silverleaf'),
(27440, 734, 0, 'Silverleaf'),
(27450, 734, 0, 'Silverleaf'),
(27459, 734, 0, 'Silverleaf'),
(27461, 734, 0, 'Silverleaf'),
(27237, 734, 0, 'Silverleaf'),
(27468, 734, 0, 'Silverleaf'),
(27495, 734, 0, 'Silverleaf'),
(27242, 734, 0, 'Silverleaf'),
(27528, 734, 0, 'Silverleaf'),
(27531, 734, 0, 'Silverleaf'),
(27538, 734, 0, 'Silverleaf'),
(33295, 734, 0, 'Silverleaf'),
(27253, 734, 0, 'Silverleaf'),
(33299, 734, 0, 'Silverleaf'),
(33957, 734, 0, 'Silverleaf'),
(33958, 734, 0, 'Silverleaf'),
(33961, 734, 0, 'Silverleaf'),
(33978, 734, 0, 'Silverleaf'),
(33983, 734, 0, 'Silverleaf'),
(27270, 734, 0, 'Silverleaf'),
(33990, 734, 0, 'Silverleaf'),
(33996, 734, 0, 'Silverleaf'),
(64908, 734, 0, 'Silverleaf'),
(64918, 734, 0, 'Silverleaf'),
(64923, 734, 0, 'Silverleaf'),
(64928, 734, 0, 'Silverleaf'),
(64931, 734, 0, 'Silverleaf'),
(64933, 734, 0, 'Silverleaf'),
(64934, 734, 0, 'Silverleaf'),

(64949, 735, 0, 'Peacebloom'),
(64950, 735, 0, 'Peacebloom'),
(64965, 735, 0, 'Peacebloom'),
(64966, 735, 0, 'Peacebloom'),
(64967, 735, 0, 'Peacebloom'),
(64968, 735, 0, 'Peacebloom'),
(27275, 735, 0, 'Peacebloom'),
(27387, 735, 0, 'Peacebloom'),
(27460, 735, 0, 'Peacebloom'),
(27466, 735, 0, 'Peacebloom'),
(27491, 735, 0, 'Peacebloom'),
(27492, 735, 0, 'Peacebloom'),
(27529, 735, 0, 'Peacebloom'),
(33296, 735, 0, 'Peacebloom'),
(33298, 735, 0, 'Peacebloom'),
(33885, 735, 0, 'Peacebloom'),
(33962, 735, 0, 'Peacebloom'),
(33988, 735, 0, 'Peacebloom'),
(33994, 735, 0, 'Peacebloom'),
(27271, 735, 0, 'Peacebloom'),
(34022, 735, 0, 'Peacebloom'),

(27273, 736, 0, 'Earthroot'),
(64984, 736, 0, 'Earthroot'),
(64991, 736, 0, 'Earthroot'),
(64995, 736, 0, 'Earthroot'),
(27310, 736, 0, 'Earthroot'),
(27209, 736, 0, 'Earthroot'),
(27426, 736, 0, 'Earthroot'),
(27430, 736, 0, 'Earthroot'),
(27456, 736, 0, 'Earthroot'),
(27496, 736, 0, 'Earthroot'),
(33956, 736, 0, 'Earthroot'),
(33973, 736, 0, 'Earthroot'),
(33995, 736, 0, 'Earthroot'),
(34021, 736, 0, 'Earthroot'),

(65006, 737, 0, 'Mageroyal'),
(65015, 737, 0, 'Mageroyal'),
(65021, 737, 0, 'Mageroyal'),
(27323, 737, 0, 'Mageroyal'),
(27427, 737, 0, 'Mageroyal'),
(27233, 737, 0, 'Mageroyal'),
(27513, 737, 0, 'Mageroyal'),
(27526, 737, 0, 'Mageroyal'),
(27527, 737, 0, 'Mageroyal'),
(27537, 737, 0, 'Mageroyal'),
(33963, 737, 0, 'Mageroyal'),
(33975, 737, 0, 'Mageroyal'),
(33985, 737, 0, 'Mageroyal'),
(33993, 737, 0, 'Mageroyal'),
(34015, 737, 0, 'Mageroyal'),

(65024, 738, 0, 'Briarthorn'),
(65025, 738, 0, 'Briarthorn'),
(65045, 738, 0, 'Briarthorn'),
(27294, 738, 0, 'Briarthorn'),
(27308, 738, 0, 'Briarthorn'),
(27386, 738, 0, 'Briarthorn'),
(27458, 738, 0, 'Briarthorn'),
(27535, 738, 0, 'Briarthorn'),
(33297, 738, 0, 'Briarthorn'),
(27269, 738, 0, 'Briarthorn'),
(33965, 738, 0, 'Briarthorn'),
(33982, 738, 0, 'Briarthorn'),
(33986, 738, 0, 'Briarthorn'),
(33991, 738, 0, 'Briarthorn'),

(27433, 739, 0, 'Stranglekelp'),
(27434, 739, 0, 'Stranglekelp'),
(27457, 739, 0, 'Stranglekelp'),
(27494, 739, 0, 'Stranglekelp'),
(34005, 739, 0, 'Stranglekelp'),
(34014, 739, 0, 'Stranglekelp'),

(65064, 740, 0, 'Bruiseweed'),
(27302, 740, 0, 'Bruiseweed'),
(27309, 740, 0, 'Bruiseweed'),
(27451, 740, 0, 'Bruiseweed'),
(27539, 740, 0, 'Bruiseweed'),
(27540, 740, 0, 'Bruiseweed'),
(33289, 740, 0, 'Bruiseweed'),
(33960, 740, 0, 'Bruiseweed'),
(34013, 740, 0, 'Bruiseweed');

-- Bloodmyst Isle Old Pool 11648
UPDATE `gameobject` SET `ZoneId`=3525 WHERE `guid` IN (86179,86192,86213,86237,86252,86267,86931,87058,2134867,2134967,2134968,2134969,2134970,2134971,2134972,2134973,2134974,2134975,2134976,2134977,2134978,2134980,2134981,2134982,2134983,2134984,2134985,2134986,2134987,2134988,2134989,2134990,2134991,2134992,2134993,2134994,2134995,2134996,2134997,2134998,2134999,2135000,2135001,2135002,2135003,2135004,2135005,2135006,2135007,2135008,2135009,2135010,2135011,2135012,2135013,2135014,2135015,2135016,2135017,2135018,2135019,2135020,2135021,2135022,2135023,2135024,2135025,2135026,2135027,2135028,2135029,2135030,2135031,2135032,2135033,2135034,2135035,2135036,2135037,2135038,2135039,2135040,2135041,2135042,2135043,2135044,2135045,2135046,2135047,2135048,2135049,2135050,2135051,2135052,2135053,2135054,2135055,2135056,2135057,2135058,2135059,2135060,2135061,2135062,2135063,2135064,2135065,2135066,2135067,2135068,2135069,2135070,2135071,2135072,2135073,2135074,2135075,2135076,2135077,2135078,2135079,2135080,2135081,2135082,2135083,2135084,2135085,2135086,2135087,2135088,2135089,2135090,2135091,2135092,2135093,2135094,2135095,2135096,2135097,2135098,2135099,2135100,2135101,2135102,2135103,2135104,2135105,2135106,2135107,2135108,2135109,2135110,2135111,2135112,2135113,2135114,2135115,2135116,2135117,2135118,2135119,2135120,2135121,2135122,2135123,2135124,2135125,2135126,2135127,2135128,2135129,2135130,2135131,2135132,2135133,2135134,2135135,2135136,2135137,2135138,2135139,2135140,2135141,2135142,2135143,2135144,2135145,2135146,2135147,2135148,2135149,2135150,2135151,2135152,2135153,2135154,2135155,2135156,2135157,2135158,2135159,2135160,2135161,2135162,2135164,2135165,2135166,2135167,2135168,2135169,2135170,2135171,2135172,2135173,2135174,2135175,2135176,2135177,2135178,2135179,2135180,2135181,2135182,2135183,2135184,2135185,2135186,2135187,2135188,2135189,2135190,2135191,2135192,2135193,2135194,2135195,2135196,2135197,2135198,2135199,2135200,2135201,2135202,2135203,2135204,2135205,2135206,2135207,2135208,2135209,2135210,2135211,2135212,2135213,2135214,2135215,2135216,2135217,2135218,2135219,2135220,2135221,2135222,2135223,2135224,2135225,2135226,2135227,2135228,2135229,2135230,2135231,2135232,2135233,2135234,2135235,2135236,2135237,2135238,2135239,2135240,2135241,2135242,2135243,2135253);

DELETE FROM `pool_template` WHERE `entry`=11648;
DELETE FROM `pool_gameobject` WHERE `pool_entry`=11648;

DELETE FROM `pool_template` WHERE `entry` BETWEEN 741 AND 747;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(741, 22, 'Silverleaf in Bloodmyst Isle'),
(742, 16, 'Peacebloom in Bloodmyst Isle'),
(743, 12, 'Earthroot in Bloodmyst Isle'),
(744, 8, 'Mageroyal in Bloodmyst Isle'),
(745, 9, 'Briarthorn in Bloodmyst Isle'),
(746, 5, 'Bruiseweed in Bloodmyst Isle'),
(747, 8, 'Stranglekelp in Bloodmyst Isle');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 741 AND 747;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(86213, 741, 0, 'Silverleaf'),
(86267, 741, 0, 'Silverleaf'),
(2134967, 741, 0, 'Silverleaf'),
(2134970, 741, 0, 'Silverleaf'),
(2134975, 741, 0, 'Silverleaf'),
(2134976, 741, 0, 'Silverleaf'),
(2134977, 741, 0, 'Silverleaf'),
(2134987, 741, 0, 'Silverleaf'),
(2134988, 741, 0, 'Silverleaf'),
(2134990, 741, 0, 'Silverleaf'),
(2134997, 741, 0, 'Silverleaf'),
(2135002, 741, 0, 'Silverleaf'),
(2135005, 741, 0, 'Silverleaf'),
(2135013, 741, 0, 'Silverleaf'),
(2135017, 741, 0, 'Silverleaf'),
(2135022, 741, 0, 'Silverleaf'),
(2135024, 741, 0, 'Silverleaf'),
(2135030, 741, 0, 'Silverleaf'),
(2135039, 741, 0, 'Silverleaf'),
(2135042, 741, 0, 'Silverleaf'),
(2135045, 741, 0, 'Silverleaf'),
(2135054, 741, 0, 'Silverleaf'),
(2135055, 741, 0, 'Silverleaf'),
(2135057, 741, 0, 'Silverleaf'),
(2135058, 741, 0, 'Silverleaf'),
(2135059, 741, 0, 'Silverleaf'),
(2135068, 741, 0, 'Silverleaf'),
(2135070, 741, 0, 'Silverleaf'),
(2135071, 741, 0, 'Silverleaf'),
(2135072, 741, 0, 'Silverleaf'),
(2135080, 741, 0, 'Silverleaf'),
(2135088, 741, 0, 'Silverleaf'),
(2135090, 741, 0, 'Silverleaf'),
(2135092, 741, 0, 'Silverleaf'),
(2135093, 741, 0, 'Silverleaf'),
(2135095, 741, 0, 'Silverleaf'),
(2135096, 741, 0, 'Silverleaf'),
(2135102, 741, 0, 'Silverleaf'),
(2135116, 741, 0, 'Silverleaf'),
(2135117, 741, 0, 'Silverleaf'),
(2135120, 741, 0, 'Silverleaf'),
(2135130, 741, 0, 'Silverleaf'),
(2135131, 741, 0, 'Silverleaf'),
(2135137, 741, 0, 'Silverleaf'),
(2135147, 741, 0, 'Silverleaf'),
(2135152, 741, 0, 'Silverleaf'),
(2135153, 741, 0, 'Silverleaf'),
(2135158, 741, 0, 'Silverleaf'),
(2135159, 741, 0, 'Silverleaf'),
(2135164, 741, 0, 'Silverleaf'),
(2135166, 741, 0, 'Silverleaf'),
(2135176, 741, 0, 'Silverleaf'),
(2135180, 741, 0, 'Silverleaf'),
(2135187, 741, 0, 'Silverleaf'),
(2135206, 741, 0, 'Silverleaf'),
(2135207, 741, 0, 'Silverleaf'),
(2135208, 741, 0, 'Silverleaf'),
(2135211, 741, 0, 'Silverleaf'),
(2135224, 741, 0, 'Silverleaf'),
(2135234, 741, 0, 'Silverleaf'),
(2135235, 741, 0, 'Silverleaf'),
(2135236, 741, 0, 'Silverleaf'),

(86192, 742, 0, 'Peacebloom'),
(2134989, 742, 0, 'Peacebloom'),
(2134996, 742, 0, 'Peacebloom'),
(2134998, 742, 0, 'Peacebloom'),
(2135003, 742, 0, 'Peacebloom'),
(2135008, 742, 0, 'Peacebloom'),
(2135011, 742, 0, 'Peacebloom'),
(2135012, 742, 0, 'Peacebloom'),
(2135016, 742, 0, 'Peacebloom'),
(2135019, 742, 0, 'Peacebloom'),
(2135044, 742, 0, 'Peacebloom'),
(2135046, 742, 0, 'Peacebloom'),
(2135051, 742, 0, 'Peacebloom'),
(2135053, 742, 0, 'Peacebloom'),
(2135062, 742, 0, 'Peacebloom'),
(2135063, 742, 0, 'Peacebloom'),

(2135078, 742, 0, 'Peacebloom'),
(2135079, 742, 0, 'Peacebloom'),
(2135083, 742, 0, 'Peacebloom'),
(2135084, 742, 0, 'Peacebloom'),
(2135101, 742, 0, 'Peacebloom'),
(2135103, 742, 0, 'Peacebloom'),
(2135108, 742, 0, 'Peacebloom'),
(2135115, 742, 0, 'Peacebloom'),
(2135118, 742, 0, 'Peacebloom'),
(2135128, 742, 0, 'Peacebloom'),
(2135132, 742, 0, 'Peacebloom'),
(2135138, 742, 0, 'Peacebloom'),
(2135140, 742, 0, 'Peacebloom'),
(2135141, 742, 0, 'Peacebloom'),
(2135142, 742, 0, 'Peacebloom'),
(2135146, 742, 0, 'Peacebloom'),
(2135150, 742, 0, 'Peacebloom'),
(2135151, 742, 0, 'Peacebloom'),
(2135161, 742, 0, 'Peacebloom'),
(2135165, 742, 0, 'Peacebloom'),
(2135167, 742, 0, 'Peacebloom'),
(2135179, 742, 0, 'Peacebloom'),
(2135184, 742, 0, 'Peacebloom'),
(2135195, 742, 0, 'Peacebloom'),
(2135203, 742, 0, 'Peacebloom'),
(2135204, 742, 0, 'Peacebloom'),
(2135217, 742, 0, 'Peacebloom'),
(2135223, 742, 0, 'Peacebloom'),
(2135230, 742, 0, 'Peacebloom'),
(2135240, 742, 0, 'Peacebloom'),

(2134867, 743, 0, 'Earthroot'),
(2134973, 743, 0, 'Earthroot'),
(2134974, 743, 0, 'Earthroot'),
(2134981, 743, 0, 'Earthroot'),
(2134985, 743, 0, 'Earthroot'),
(2134986, 743, 0, 'Earthroot'),
(2134995, 743, 0, 'Earthroot'),
(2135000, 743, 0, 'Earthroot'),
(2135001, 743, 0, 'Earthroot'),
(2135009, 743, 0, 'Earthroot'),
(2135014, 743, 0, 'Earthroot'),
(2135015, 743, 0, 'Earthroot'),
(2135021, 743, 0, 'Earthroot'),
(2135029, 743, 0, 'Earthroot'),
(2135031, 743, 0, 'Earthroot'),
(2135040, 743, 0, 'Earthroot'),
(2135041, 743, 0, 'Earthroot'),
(2135050, 743, 0, 'Earthroot'),
(2135065, 743, 0, 'Earthroot'),
(2135066, 743, 0, 'Earthroot'),
(2135098, 743, 0, 'Earthroot'),
(2135122, 743, 0, 'Earthroot'),
(2135126, 743, 0, 'Earthroot'),
(2135127, 743, 0, 'Earthroot'),
(2135143, 743, 0, 'Earthroot'),
(2135170, 743, 0, 'Earthroot'),
(2135178, 743, 0, 'Earthroot'),
(2135186, 743, 0, 'Earthroot'),
(2135191, 743, 0, 'Earthroot'),
(2135192, 743, 0, 'Earthroot'),
(2135201, 743, 0, 'Earthroot'),
(2135210, 743, 0, 'Earthroot'),
(2135220, 743, 0, 'Earthroot'),
(2135221, 743, 0, 'Earthroot'),
(2135227, 743, 0, 'Earthroot'),

(2134971, 744, 0, 'Mageroyal'),
(2134982, 744, 0, 'Mageroyal'),
(2135004, 744, 0, 'Mageroyal'),
(2135007, 744, 0, 'Mageroyal'),
(2135018, 744, 0, 'Mageroyal'),
(2135028, 744, 0, 'Mageroyal'),
(2135036, 744, 0, 'Mageroyal'),
(2135043, 744, 0, 'Mageroyal'),
(2135052, 744, 0, 'Mageroyal'),
(2135064, 744, 0, 'Mageroyal'),
(2135085, 744, 0, 'Mageroyal'),
(2135089, 744, 0, 'Mageroyal'),
(2135091, 744, 0, 'Mageroyal'),
(2135094, 744, 0, 'Mageroyal'),
(2135104, 744, 0, 'Mageroyal'),
(2135109, 744, 0, 'Mageroyal'),
(2135124, 744, 0, 'Mageroyal'),
(2135129, 744, 0, 'Mageroyal'),
(2135133, 744, 0, 'Mageroyal'),
(2135144, 744, 0, 'Mageroyal'),
(2135148, 744, 0, 'Mageroyal'),
(2135149, 744, 0, 'Mageroyal'),
(2135157, 744, 0, 'Mageroyal'),
(2135168, 744, 0, 'Mageroyal'),
(2135171, 744, 0, 'Mageroyal'),
(2135174, 744, 0, 'Mageroyal'),
(2135200, 744, 0, 'Mageroyal'),
(2135214, 744, 0, 'Mageroyal'),
(2135216, 744, 0, 'Mageroyal'),
(2135222, 744, 0, 'Mageroyal'),
(2135226, 744, 0, 'Mageroyal'),
(2135231, 744, 0, 'Mageroyal'),

(86179, 745, 0, 'Briarthorn'),
(86252, 745, 0, 'Briarthorn'),
(87058, 745, 0, 'Briarthorn'),
(2134968, 745, 0, 'Briarthorn'),
(2134969, 745, 0, 'Briarthorn'),
(2134972, 745, 0, 'Briarthorn'),
(2134978, 745, 0, 'Briarthorn'),
(2134980, 745, 0, 'Briarthorn'),
(2134984, 745, 0, 'Briarthorn'),
(2134992, 745, 0, 'Briarthorn'),
(2134993, 745, 0, 'Briarthorn'),
(2134994, 745, 0, 'Briarthorn'),
(2134999, 745, 0, 'Briarthorn'),
(2135006, 745, 0, 'Briarthorn'),
(2135025, 745, 0, 'Briarthorn'),
(2135026, 745, 0, 'Briarthorn'),
(2135033, 745, 0, 'Briarthorn'),
(2135034, 745, 0, 'Briarthorn'),
(2135037, 745, 0, 'Briarthorn'),
(2135048, 745, 0, 'Briarthorn'),
(2135049, 745, 0, 'Briarthorn'),
(2135060, 745, 0, 'Briarthorn'),
(2135073, 745, 0, 'Briarthorn'),
(2135074, 745, 0, 'Briarthorn'),
(2135081, 745, 0, 'Briarthorn'),
(2135082, 745, 0, 'Briarthorn'),
(2135086, 745, 0, 'Briarthorn'),
(2135110, 745, 0, 'Briarthorn'),
(2135111, 745, 0, 'Briarthorn'),
(2135112, 745, 0, 'Briarthorn'),
(2135113, 745, 0, 'Briarthorn'),
(2135121, 745, 0, 'Briarthorn'),
(2135134, 745, 0, 'Briarthorn'),
(2135135, 745, 0, 'Briarthorn'),
(2135175, 745, 0, 'Briarthorn'),
(2135182, 745, 0, 'Briarthorn'),
(2135185, 745, 0, 'Briarthorn'),
(2135189, 745, 0, 'Briarthorn'),
(2135190, 745, 0, 'Briarthorn'),
(2135194, 745, 0, 'Briarthorn'),
(2135196, 745, 0, 'Briarthorn'),
(2135197, 745, 0, 'Briarthorn'),
(2135205, 745, 0, 'Briarthorn'),
(2135219, 745, 0, 'Briarthorn'),
(2135242, 745, 0, 'Briarthorn'),
(2135243, 745, 0, 'Briarthorn'),

(86931, 746, 0, 'Bruiseweed'),
(2134983, 746, 0, 'Bruiseweed'),
(2134991, 746, 0, 'Bruiseweed'),
(2135047, 746, 0, 'Bruiseweed'),
(2135097, 746, 0, 'Bruiseweed'),
(2135105, 746, 0, 'Bruiseweed'),
(2135145, 746, 0, 'Bruiseweed'),
(2135154, 746, 0, 'Bruiseweed'),
(2135155, 746, 0, 'Bruiseweed'),
(2135169, 746, 0, 'Bruiseweed'),
(2135173, 746, 0, 'Bruiseweed'),
(2135181, 746, 0, 'Bruiseweed'),
(2135199, 746, 0, 'Bruiseweed'),
(2135212, 746, 0, 'Bruiseweed'),
(2135213, 746, 0, 'Bruiseweed'),
(2135237, 746, 0, 'Bruiseweed'),
(2135241, 746, 0, 'Bruiseweed'),

(86237, 747, 0, 'Stranglekelp'),
(2135010, 747, 0, 'Stranglekelp'),
(2135027, 747, 0, 'Stranglekelp'),
(2135032, 747, 0, 'Stranglekelp'),
(2135035, 747, 0, 'Stranglekelp'),
(2135061, 747, 0, 'Stranglekelp'),
(2135067, 747, 0, 'Stranglekelp'),
(2135075, 747, 0, 'Stranglekelp'),
(2135076, 747, 0, 'Stranglekelp'),
(2135087, 747, 0, 'Stranglekelp'),
(2135099, 747, 0, 'Stranglekelp'),
(2135100, 747, 0, 'Stranglekelp'),
(2135106, 747, 0, 'Stranglekelp'),
(2135107, 747, 0, 'Stranglekelp'),
(2135114, 747, 0, 'Stranglekelp'),
(2135123, 747, 0, 'Stranglekelp'),
(2135139, 747, 0, 'Stranglekelp'),
(2135156, 747, 0, 'Stranglekelp'),
(2135160, 747, 0, 'Stranglekelp'),
(2135183, 747, 0, 'Stranglekelp'),
(2135193, 747, 0, 'Stranglekelp'),
(2135202, 747, 0, 'Stranglekelp'),
(2135228, 747, 0, 'Stranglekelp'),
(2135233, 747, 0, 'Stranglekelp'),
(2135238, 747, 0, 'Stranglekelp'),
(2135239, 747, 0, 'Stranglekelp');

-- Wyrmscar Isle
DELETE FROM `pool_template` WHERE `entry` BETWEEN 748 AND 751;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(748, 2, 'Peacebloom in Wyrmscar Isle'),
(749, 2, 'Silverleaf in Wyrmscar Isle'),
(750, 1, 'Mageroyal in Wyrmscar Isle'),
(751, 1, 'Bruiseweed in Wyrmscar Isle');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN 748 AND 751;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(2135069, 748, 0, 'Peacebloom'),
(2135020, 748, 0, 'Peacebloom'),
(2135038, 748, 0, 'Peacebloom'),
(2135077, 748, 0, 'Peacebloom'),
(2135215, 748, 0, 'Peacebloom'),

(2135177, 749, 0, 'Silverleaf'),
(2135225, 749, 0, 'Silverleaf'),
(2135136, 749, 0, 'Silverleaf'),
(2135056, 749, 0, 'Silverleaf'),
(2135188, 749, 0, 'Silverleaf'),

(2135229, 750, 0, 'Mageroyal'),
(2135162, 750, 0, 'Mageroyal'),
(2135198, 750, 0, 'Mageroyal'),
(2135125, 750, 0, 'Mageroyal'),
(2135023, 750, 0, 'Mageroyal'),
(2135209, 750, 0, 'Mageroyal'),

(2135172, 751, 0, 'Bruiseweed'),
(2135232, 751, 0, 'Bruiseweed'),
(2135253, 751, 0, 'Bruiseweed'),
(2135218, 751, 0, 'Bruiseweed'),
(2135119, 751, 0, 'Bruiseweed');
