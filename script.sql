CREATE SCHEMA IF NOT EXISTS `grow` DEFAULT CHARACTER SET utf8 ;
USE `grow` ;

CREATE TABLE IF NOT EXISTS `grow`.`devices` (
`id` INT NOT NULL AUTO_INCREMENT,
`name_owner` VARCHAR(45) NULL,
`address` VARCHAR(45) NULL,
`version_po` VARCHAR(45) NULL,
`comment` VARCHAR(45) NULL,
`date_buy` VARCHAR(45) NULL,
PRIMARY KEY (`id`))
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`settings` (
`id` INT AUTO_INCREMENT,
`device_id` INT NULL,
`settings` TEXT(255) NULL COMMENT 'json строка с настройками',
PRIMARY KEY (`id`),
INDEX `device_id_idx` (`device_id` ASC),
CONSTRAINT `device_id`
FOREIGN KEY (`device_id`)
REFERENCES `grow`.`devices` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`sensors` (
`id` INT AUTO_INCREMENT,
`name` INT NULL,
PRIMARY KEY (`id`))
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`sensor_data` (
`id` INT AUTO_INCREMENT,
`device_id` INT NULL,
`sensor_id` INT NULL,
`data` FLOAT NULL,
`date_add` DATETIME NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
PRIMARY KEY (`id`),
INDEX `dvc_idx` (`device_id` ASC),
INDEX `scnc_idx` (`sensor_id` ASC),
CONSTRAINT `dvc`
FOREIGN KEY (`device_id`)
REFERENCES `grow`.`devices` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION,
CONSTRAINT `scnc`
FOREIGN KEY (`sensor_id`)
REFERENCES `grow`.`sensors` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`sensor_in_device` (
`device_id` INT NULL,
`sensor_id` INT NULL,
`id` INT,
PRIMARY KEY (`id`),
INDEX `dv_id_idx` (`device_id` ASC),
INDEX `sn_id_idx` (`sensor_id` ASC),
CONSTRAINT `dv_id`
FOREIGN KEY (`device_id`)
REFERENCES `grow`.`devices` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION,
CONSTRAINT `sn_id`
FOREIGN KEY (`sensor_id`)
REFERENCES `grow`.`sensors` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`culture` (
`id` INT AUTO_INCREMENT,
`name` VARCHAR(45) NULL,
`desctiption` VARCHAR(45) NULL,
PRIMARY KEY (`id`))
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `grow`.`culture_in_device` (
`device_id` INT NULL,
`culture_id` INT NULL,
`level` INT NULL COMMENT 'Уровень на котором располагается культура\n',
INDEX `dvc_id_idx` (`device_id` ASC),
INDEX `cultr_id_idx` (`culture_id` ASC),
CONSTRAINT `dvc_id`
FOREIGN KEY (`device_id`)
REFERENCES `grow`.`devices` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION,
CONSTRAINT `cultr_id`
FOREIGN KEY (`culture_id`)
REFERENCES `grow`.`culture` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION)
ENGINE = InnoDB;

/*SET SQL_MODE=@NO_AUTO_VALUE_ON_ZERO;*/
/*SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;*/
/*SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;*/
