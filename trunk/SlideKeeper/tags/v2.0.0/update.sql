#
#  Fix the Picture in tb_slides to a integer key.
#
ALTER TABLE `vrl`.`tb_slides` MODIFY COLUMN `Picture` VARCHAR(255) NOT NULL
, DROP PRIMARY KEY
, ADD PRIMARY KEY(`tb_SlideKey`);


#
#  Fix the Date in tb_slides to a variable Character.
#
ALTER TABLE `vrl`.`tb_slides` MODIFY COLUMN `tb_Date` VARCHAR(20) NOT NULL
, DROP PRIMARY KEY
, ADD PRIMARY KEY(`tb_SlideKey`);

#
#  Create a Counter to track identifying numbers.
#
CREATE TABLE `vrl`.`tb_PictureCounter` (
  `Counter` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY
);

SET PASSWORD FOR 'vrluser'@'%' = OLD_PASSWORD('vrlpass');