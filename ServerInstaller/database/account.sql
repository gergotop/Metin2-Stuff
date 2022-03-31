/*
 Navicat Premium Data Transfer

 Source Server         : asd
 Source Server Type    : MySQL
 Source Server Version : 50651
 Source Host           : localhost:3306
 Source Schema         : account

 Target Server Type    : MySQL
 Target Server Version : 50651
 File Encoding         : 65001

 Date: 31/03/2022 09:09:31
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(30) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT '',
  `password` varchar(45) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT '',
  `social_id` varchar(13) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT '',
  `email` varchar(64) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT '',
  `create_time` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `is_testor` tinyint(1) NOT NULL DEFAULT 0,
  `status` varchar(8) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT 'OK',
  `securitycode` varchar(192) CHARACTER SET ascii COLLATE ascii_general_ci NULL DEFAULT '',
  `newsletter` tinyint(1) NULL DEFAULT 0,
  `empire` tinyint(4) NOT NULL DEFAULT 0,
  `name_checked` tinyint(1) NOT NULL DEFAULT 0,
  `availDt` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `mileage` int(11) NOT NULL DEFAULT 0,
  `cash` int(11) NOT NULL DEFAULT 0,
  `gold_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `silver_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `safebox_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `autoloot_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `fish_mind_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `marriage_fast_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `money_drop_rate_expire` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `total_cash` int(11) NOT NULL DEFAULT 0,
  `total_mileage` int(11) NOT NULL DEFAULT 0,
  `channel_company` varchar(30) CHARACTER SET ascii COLLATE ascii_general_ci NOT NULL DEFAULT '',
  `ip` varchar(255) CHARACTER SET ascii COLLATE ascii_general_ci NULL DEFAULT NULL,
  `last_play` datetime(0) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `login`(`login`) USING BTREE,
  INDEX `social_id`(`social_id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 3 CHARACTER SET = ascii COLLATE = ascii_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of account
-- ----------------------------
INSERT INTO `account` VALUES (1, 'admin', '*CC67043C7BCFF5EEA5566BD9B1F3C74FD9A5CF5D', '1234567', '', '0000-00-00 00:00:00', 0, 'OK', '', 0, 0, 0, '0000-00-00 00:00:00', 0, 1650, '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 0, '', NULL, '2021-11-21 20:10:46');
INSERT INTO `account` VALUES (2, 'test', '*CC67043C7BCFF5EEA5566BD9B1F3C74FD9A5CF5D', '1234567', '', '0000-00-00 00:00:00', 0, 'OK', '', 0, 0, 0, '0000-00-00 00:00:00', 0, 0, '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 0, '', NULL, '2021-08-06 11:42:12');

-- ----------------------------
-- Table structure for block_exception
-- ----------------------------
DROP TABLE IF EXISTS `block_exception`;
CREATE TABLE `block_exception`  (
  `login` int(11) NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of block_exception
-- ----------------------------
INSERT INTO `block_exception` VALUES (100);

-- ----------------------------
-- Table structure for gametime
-- ----------------------------
DROP TABLE IF EXISTS `gametime`;
CREATE TABLE `gametime`  (
  `UserID` varchar(50) CHARACTER SET euckr COLLATE euckr_korean_ci NOT NULL DEFAULT '',
  `paymenttype` tinyint(2) NOT NULL DEFAULT 1,
  `LimitTime` int(11) NULL DEFAULT 0,
  `LimitDt` datetime(0) NULL DEFAULT '1990-01-01 00:00:00',
  `Scores` int(11) NULL DEFAULT 0,
  PRIMARY KEY (`UserID`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = euckr COLLATE = euckr_korean_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for gametimeip
-- ----------------------------
DROP TABLE IF EXISTS `gametimeip`;
CREATE TABLE `gametimeip`  (
  `ipid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) CHARACTER SET euckr COLLATE euckr_korean_ci NULL DEFAULT NULL,
  `ip` varchar(11) CHARACTER SET euckr COLLATE euckr_korean_ci NOT NULL DEFAULT '000.000.000',
  `startIP` int(11) NOT NULL DEFAULT 0,
  `endIP` int(11) NOT NULL DEFAULT 255,
  `paymenttype` tinyint(2) NOT NULL DEFAULT 1,
  `LimitTime` int(11) NOT NULL DEFAULT 0,
  `LimitDt` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `readme` varchar(128) CHARACTER SET euckr COLLATE euckr_korean_ci NULL DEFAULT NULL,
  PRIMARY KEY (`ipid`) USING BTREE,
  UNIQUE INDEX `ip_uniq`(`ip`, `startIP`, `endIP`) USING BTREE,
  INDEX `ip_idx`(`ip`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = euckr COLLATE = euckr_korean_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for gametimelog
-- ----------------------------
DROP TABLE IF EXISTS `gametimelog`;
CREATE TABLE `gametimelog`  (
  `login` varchar(16) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  `type` enum('IP_FREE','FREE','IP_TIME','IP_DAY','TIME','DAY') CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  `logon_time` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `logout_time` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `use_time` int(11) NULL DEFAULT NULL,
  `ip` varchar(15) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '000.000.000.000',
  `server` varchar(32) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '',
  INDEX `login_key`(`login`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for iptocountry
-- ----------------------------
DROP TABLE IF EXISTS `iptocountry`;
CREATE TABLE `iptocountry`  (
  `IP_FROM` varchar(16) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `IP_TO` varchar(16) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `COUNTRY_NAME` varchar(16) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of iptocountry
-- ----------------------------
INSERT INTO `iptocountry` VALUES ('', '', '');

-- ----------------------------
-- Table structure for string
-- ----------------------------
DROP TABLE IF EXISTS `string`;
CREATE TABLE `string`  (
  `name` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `text` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
