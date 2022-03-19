SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

CREATE DATABASE IF NOT EXISTS test;

CREATE TABLE `files` (
  `id_file` int(11) NOT NULL,
  `id_my` int(11) NOT NULL,
  `description` text NOT NULL,
  `name_origin` text NOT NULL,
  `path` text NOT NULL,
  `date_upload` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;

INSERT INTO `files` (`id_file`, `id_my`, `description`, `name_origin`, `path`, `date_upload`) VALUES
(16, 17, 'Закачка из менеджера', 'Стратегии в виртуальном футболе.pdf', 'files/Стратегии в виртуальном футболе.pdf', '16-03-2022  08:41:22');

CREATE TABLE `myarttable` (
  `id` int(11) NOT NULL,
  `text` text NOT NULL,
  `description` text NOT NULL,
  `keywords` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;

INSERT INTO `myarttable` (`id`, `text`, `description`, `keywords`) VALUES
(17, 'Baranov', 'Engeneer', 'Ivanov'),
(20, 'Fedorov', 'Cpp, Delphi, PHP, JS', '3t'),
(21, 'Степанов', 'машинист', 'РЖД'),
(22, 'new test...', 'desc.', 'key1, ...'),
(23, 'new test...', 'desc.', 'key1, ...'),
(24, 'at1', 'at2', 'at3'),
(25, 'new text1', 'new desc2', 'key3'),
(26, 'new text1', 'new desc2', 'key3'),
(27, 'new test...', 'desc.', 'key1, ...'),
(28, 'at1', 'at2', 'at3'),
(29, 'at1', 'at2', 'at3'),
(30, 'new test...', 'desc.', 'key1, ...'),
(31, 'new text1', 'new desc2', 'key3'),
(32, 'new test...', 'desc.', 'key1, ...'),
(33, 'at1', 'at2', 'at3'),
(34, 'one...', 'two.', 'three is k.'),
(35, 'new test...', 'desc.', 'key1, ...'),
(36, 'one...', 'two.', 'three is k.'),
(37, 'one...', 'two.', 'three is k.'),
(38, 'new text1', 'new desc2', 'key3');

ALTER TABLE `files`
  ADD PRIMARY KEY (`id_file`),
  ADD KEY `id_my` (`id_my`);

ALTER TABLE `myarttable`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `files`
  MODIFY `id_file` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

ALTER TABLE `myarttable`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=39;

ALTER TABLE `files`
  ADD CONSTRAINT `files_ibfk_1` FOREIGN KEY (`id_my`) REFERENCES `myarttable` (`id`);
COMMIT;
