-- DB update 2021_08_05_00 -> 2021_08_05_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_08_05_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_08_05_00 2021_08_05_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1627393900919186826'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1627393900919186826');

-- Add movement to various Starving Ghostclaws
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 5 WHERE `id` = 16347 AND `guid` IN (81746, 81747, 81748, 81749, 81750, 81751, 81754, 81759, 81760, 81761, 81762, 81763, 81793, 81892, 82042, 82044, 82092, 82099, 82105, 82115, 82117, 82120, 82121, 82128, 82769);

-- Add movement to various Mistbats
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 5 WHERE `id` = 16353 AND `guid` IN (81752, 81753, 81755, 81758, 81782, 81794, 82045, 82079, 82100, 82109, 82114, 82116, 82118, 82119, 82464, 82473, 82474);


--
-- END UPDATING QUERIES
--
UPDATE version_db_world SET date = '2021_08_05_01' WHERE sql_rev = '1627393900919186826';
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
