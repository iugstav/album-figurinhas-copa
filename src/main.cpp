#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include "Album.h"
#include "Colecao.h"
#include "Figurinha.h"
#include "Colecionador.h"

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s)
{
	return rtrim(ltrim(s));
}

// armazena todas as figurinhas em memória e retorna todas como um vetor.
vector<Figurinha> initialize_data()
{
	vector<Figurinha> store = {
			Figurinha(0, "0", "Panini", "Content", "foil"),
			Figurinha(1, "FWC1", "FIFA", "Content", "-"),
			Figurinha(2, "FWC2", "Official Trophy1", "Content", "foil"),
			Figurinha(3, "FWC3", "Official Trophy2", "Content", "foil"),
			Figurinha(4, "FWC4", "Official Mascot1", "Content", "foil"),
			Figurinha(5, "FWC5", "Official Mascot2", "Content", "foil"),
			Figurinha(6, "FWC6", "Official Emblem1", "Content", "foil"),
			Figurinha(7, "FWC7", "Official Emblem2", "Content", "foil"),
			Figurinha(8, "FWC8", "Ahmad Bin Ali Stadium", "Stadiums", "-"),
			Figurinha(9, "FWC9", "Al Janoub Stadium", "Stadiums", "-"),
			Figurinha(10, "FWC10", "Al Thumama Stadium", "Stadiums", "-"),
			Figurinha(11, "FWC11", "Education City Stadium", "Stadiums", "-"),
			Figurinha(12, "FWC12", "Khalifa International Stadium", "Stadiums", "-"),
			Figurinha(13, "FWC13", "Stadium 974", "Stadiums", "-"),
			Figurinha(14, "FWC14", "Al Bayt Stadium outdoor", "Stadiums", "-"),
			Figurinha(15, "FWC15", "Al Bayt Stadium indoor", "Stadiums", "-"),
			Figurinha(16, "FWC16", "Lusail Stadium outdoor", "Stadiums", "-"),
			Figurinha(17, "FWC17", "Lusail Stadium indoor", "Stadiums", "-"),
			Figurinha(18, "FWC18", "Al Rihla", "Official Match Ball", "-"),
			Figurinha(19, "QAT1", "Team Shot", "Qatar", "-"),
			Figurinha(20, "QAT2", "Team Logo", "Qatar", "foil"),
			Figurinha(21, "QAT3", "Saad Al Sheeb", "Qatar", "-"),
			Figurinha(22, "QAT4", "Meshaal Barsham", "Qatar", "-"),
			Figurinha(23, "QAT5", "Homam Ahmed", "Qatar", "-"),
			Figurinha(24, "QAT6", "Bassam Alrawi", "Qatar", "-"),
			Figurinha(25, "QAT7", "Abdulkarim Hassan", "Qatar", "-"),
			Figurinha(26, "QAT8", "Musaab Khidir", "Qatar", "-"),
			Figurinha(27, "QAT9", "Boualem Khoukhi", "Qatar", "-"),
			Figurinha(28, "QAT10", "Pedro Miguel", "Qatar", "-"),
			Figurinha(29, "QAT11", "Tarek Salman", "Qatar", "-"),
			Figurinha(30, "QAT12", "Karim Boudiaf", "Qatar", "-"),
			Figurinha(31, "QAT13", "Abdulaziz Hatem", "Qatar", "-"),
			Figurinha(32, "QAT14", "Assim Omer Madibo", "Qatar", "-"),
			Figurinha(33, "QAT15", "Yousuf Abdurisag", "Qatar", "-"),
			Figurinha(34, "QAT16", "Akram Hassan Afif", "Qatar", "-"),
			Figurinha(35, "QAT17", "Ahmad Alaaeldin", "Qatar", "-"),
			Figurinha(36, "QAT18", "Hasan Al-Haydos", "Qatar", "-"),
			Figurinha(37, "QAT19", "Almoez Ali", "Qatar", "-"),
			Figurinha(38, "QAT20", "Mohammed Muntari", "Qatar", "-"),
			Figurinha(39, "ECU1", "Team Shot", "Ecuador", "-"),
			Figurinha(40, "ECU2", "Team Logo", "Ecuador", "foil"),
			Figurinha(41, "ECU3", "Hern�n Gal�ndez", "Ecuador", "-"),
			Figurinha(42, "ECU4", "Alexander Dom�nguez", "Ecuador", "-"),
			Figurinha(43, "ECU5", "Robert Arboleda", "Ecuador", "-"),
			Figurinha(44, "ECU6", "Byron Castillo", "Ecuador", "-"),
			Figurinha(45, "ECU7", "Pervis Estupi��n", "Ecuador", "-"),
			Figurinha(46, "ECU8", "Piero Hincapi�", "Ecuador", "-"),
			Figurinha(47, "ECU9", "�ngelo Preciado", "Ecuador", "-"),
			Figurinha(48, "ECU10", "F�lix Torres", "Ecuador", "-"),
			Figurinha(49, "ECU11", "Mois�s Caicedo", "Ecuador", "-"),
			Figurinha(50, "ECU12", "Alan Franco", "Ecuador", "-"),
			Figurinha(51, "ECU13", "Carlos Gruezo", "Ecuador", "-"),
			Figurinha(52, "ECU14", "Jhegson M�ndez", "Ecuador", "-"),
			Figurinha(53, "ECU15", "Jeremy Sarmiento", "Ecuador", "-"),
			Figurinha(54, "ECU16", "Michael Estrada", "Ecuador", "-"),
			Figurinha(55, "ECU17", "�ngel Mena", "Ecuador", "-"),
			Figurinha(56, "ECU18", "Gonzalo Plata", "Ecuador", "-"),
			Figurinha(57, "ECU19", "Ayrton Preciado", "Ecuador", "-"),
			Figurinha(58, "ECU20", "Enner Valencia", "Ecuador", "-"),
			Figurinha(59, "SEN1", "Team Shot", "Senegal", "-"),
			Figurinha(60, "SEN2", "Team Logo", "Senegal", "foil"),
			Figurinha(61, "SEN3", "�douard Mendy", "Senegal", "-"),
			Figurinha(62, "SEN4", "Alfred Gomis", "Senegal", "-"),
			Figurinha(63, "SEN5", "Saliou Ciss", "Senegal", "-"),
			Figurinha(64, "SEN6", "Pape Abou Ciss�", "Senegal", "-"),
			Figurinha(65, "SEN7", "Abdou Diallo", "Senegal", "-"),
			Figurinha(66, "SEN8", "Kalidou Koulibaly", "Senegal", "-"),
			Figurinha(67, "SEN9", "Ibrahima Mbaye", "Senegal", "-"),
			Figurinha(68, "SEN10", "Bouna Sarr", "Senegal", "-"),
			Figurinha(69, "SEN11", "Kr�pin Diatta", "Senegal", "-"),
			Figurinha(70, "SEN12", "Idrissa Gueye", "Senegal", "-"),
			Figurinha(71, "SEN13", "Pape Gueye", "Senegal", "-"),
			Figurinha(72, "SEN14", "Cheikhou Kouyat�", "Senegal", "-"),
			Figurinha(73, "SEN15", "Nampalys Mendy", "Senegal", "-"),
			Figurinha(74, "SEN16", "Boulaye Dia", "Senegal", "-"),
			Figurinha(75, "SEN17", "Famara Di�dhiou", "Senegal", "-"),
			Figurinha(76, "SEN18", "Bamba Dieng", "Senegal", "-"),
			Figurinha(77, "SEN19", "Sadio Man�", "Senegal", "-"),
			Figurinha(78, "SEN20", "Isma�la Sarr", "Senegal", "-"),
			Figurinha(79, "NED1", "Team Shot", "Netherlands", "-"),
			Figurinha(80, "NED2", "Team Logo", "Netherlands", "foil"),
			Figurinha(81, "NED3", "Justin Bijlow", "Netherlands", "-"),
			Figurinha(82, "NED4", "Jasper Cillessen", "Netherlands", "-"),
			Figurinha(83, "NED5", "Daley Blind", "Netherlands", "-"),
			Figurinha(84, "NED6", "Matthijs de Ligt", "Netherlands", "-"),
			Figurinha(85, "NED7", "Stefan de Vrij", "Netherlands", "-"),
			Figurinha(86, "NED8", "Denzel Dumfries", "Netherlands", "-"),
			Figurinha(87, "NED9", "Virgil van Dijk", "Netherlands", "-"),
			Figurinha(88, "NED10", "Steven Berghuis", "Netherlands", "-"),
			Figurinha(89, "NED11", "Frenkie de Jong", "Netherlands", "-"),
			Figurinha(90, "NED12", "Ryan Gravenberch", "Netherlands", "-"),
			Figurinha(91, "NED13", "Davy Klaassen", "Netherlands", "-"),
			Figurinha(92, "NED14", "Teun Koopmeiners", "Netherlands", "-"),
			Figurinha(93, "NED15", "Georginio Wijnaldum", "Netherlands", "-"),
			Figurinha(94, "NED16", "Steven Bergwijn", "Netherlands", "-"),
			Figurinha(95, "NED17", "Arnaut Danjuma", "Netherlands", "-"),
			Figurinha(96, "NED18", "Memphis Depay", "Netherlands", "-"),
			Figurinha(97, "NED19", "Cody Gakpo", "Netherlands", "-"),
			Figurinha(98, "NED20", "Donyell Malen", "Netherlands", "-"),
			Figurinha(99, "ENG1", "Team Shot", "England", "-"),
			Figurinha(100, "ENG2", "Team Logo", "England", "foil"),
			Figurinha(101, "ENG3", "Jordan Pickford", "England", "-"),
			Figurinha(102, "ENG4", "Aaron Ramsdale", "England", "-"),
			Figurinha(103, "ENG5", "Trent Alexander-Arnold", "England", "-"),
			Figurinha(104, "ENG6", "Conor Coady", "England", "-"),
			Figurinha(105, "ENG7", "Harry Maguire", "England", "-"),
			Figurinha(106, "ENG8", "Luke Shaw", "England", "-"),
			Figurinha(107, "ENG9", "John Stones", "England", "-"),
			Figurinha(108, "ENG10", "Kyle Walker", "England", "-"),
			Figurinha(109, "ENG11", "Jude Bellingham", "England", "-"),
			Figurinha(110, "ENG12", "Jack Grealish", "England", "-"),
			Figurinha(111, "ENG13", "Jordan Henderson", "England", "-"),
			Figurinha(112, "ENG14", "Mason Mount", "England", "-"),
			Figurinha(113, "ENG15", "Kalvin Phillips", "England", "-"),
			Figurinha(114, "ENG16", "Declan Rice", "England", "-"),
			Figurinha(115, "ENG17", "Phil Foden", "England", "-"),
			Figurinha(116, "ENG18", "Harry Kane", "England", "-"),
			Figurinha(117, "ENG19", "Bukayo Saka", "England", "-"),
			Figurinha(118, "ENG20", "Raheem Sterling", "England", "-"),
			Figurinha(119, "IRN1", "Team Shot", "Iran", "-"),
			Figurinha(120, "IRN2", "Team Logo", "Iran", "foil"),
			Figurinha(121, "IRN3", "Amir Abedzadeh", "Iran", "-"),
			Figurinha(122, "IRN4", "Alireza Beiranvand", "Iran", "-"),
			Figurinha(123, "IRN5", "Ehsan Hajsafi", "Iran", "-"),
			Figurinha(124, "IRN6", "Majid Hosseini", "Iran", "-"),
			Figurinha(125, "IRN7", "Hossein Kanaani", "Iran", "-"),
			Figurinha(126, "IRN8", "Shoja Khalilzadeh", "Iran", "-"),
			Figurinha(127, "IRN9", "Milad Mohammadi", "Iran", "-"),
			Figurinha(128, "IRN10", "Sadegh Moharrami", "Iran", "-"),
			Figurinha(129, "IRN11", "Omid Noorafkan", "Iran", "-"),
			Figurinha(130, "IRN12", "Vahid Amiri", "Iran", "-"),
			Figurinha(131, "IRN13", "Saeid Ezatolahi", "Iran", "-"),
			Figurinha(132, "IRN14", "Ali Gholizadeh", "Iran", "-"),
			Figurinha(133, "IRN15", "Alireza Jahanbakhsh", "Iran", "-"),
			Figurinha(134, "IRN16", "Ahmad Nourollahi", "Iran", "-"),
			Figurinha(135, "IRN17", "Karim Ansarifard", "Iran", "-"),
			Figurinha(136, "IRN18", "Sardar Azmoun", "Iran", "-"),
			Figurinha(137, "IRN19", "Saman Ghoddos", "Iran", "-"),
			Figurinha(138, "IRN20", "Mehdi Taremi", "Iran", "-"),
			Figurinha(139, "USA1", "Team Shot", "USA", "-"),
			Figurinha(140, "USA2", "Team Logo", "USA", "foil"),
			Figurinha(141, "USA3", "Matt Turner", "USA", "-"),
			Figurinha(142, "USA4", "Zack Steffen", "USA", "-"),
			Figurinha(143, "USA5", "Sergi�o Dest", "USA", "-"),
			Figurinha(144, "USA6", "Aaron Long", "USA", "-"),
			Figurinha(145, "USA7", "Chris Richards", "USA", "-"),
			Figurinha(146, "USA8", "Antonee Robinson", "USA", "-"),
			Figurinha(147, "USA9", "DeAndre Yedlin", "USA", "-"),
			Figurinha(148, "USA10", "Walker Zimmerman", "USA", "-"),
			Figurinha(149, "USA11", "Brenden Aaronson", "USA", "-"),
			Figurinha(150, "USA12", "Kellyn Acosta", "USA", "-"),
			Figurinha(151, "USA13", "Tyler Adams", "USA", "-"),
			Figurinha(152, "USA14", "Weston McKennie", "USA", "-"),
			Figurinha(153, "USA15", "Yunus Musah", "USA", "-"),
			Figurinha(154, "USA16", "Jes�s Ferreira", "USA", "-"),
			Figurinha(155, "USA17", "Ricardo Pepi", "USA", "-"),
			Figurinha(156, "USA18", "Christian Pulisic", "USA", "-"),
			Figurinha(157, "USA19", "Giovanni Reyna", "USA", "-"),
			Figurinha(158, "USA20", "Timothy Weah", "USA", "-"),
			Figurinha(159, "WAL1", "Team Shot", "Wales", "-"),
			Figurinha(160, "WAL2", "Team Logo", "Wales", "foil"),
			Figurinha(161, "WAL3", "Danny Ward", "Wales", "-"),
			Figurinha(162, "WAL4", "Wayne Hennessey", "Wales", "-"),
			Figurinha(163, "WAL5", "Ethan Ampadu", "Wales", "-"),
			Figurinha(164, "WAL6", "Ben Davies", "Wales", "-"),
			Figurinha(165, "WAL7", "Chris Gunter", "Wales", "-"),
			Figurinha(166, "WAL8", "Chris Mepham", "Wales", "-"),
			Figurinha(167, "WAL9", "Connor Roberts", "Wales", "-"),
			Figurinha(168, "WAL10", "Joe Rodon", "Wales", "-"),
			Figurinha(169, "WAL11", "Neco Williams", "Wales", "-"),
			Figurinha(170, "WAL12", "Joe Allen", "Wales", "-"),
			Figurinha(171, "WAL13", "Joe Morrell", "Wales", "-"),
			Figurinha(172, "WAL14", "Aaron Ramsey", "Wales", "-"),
			Figurinha(173, "WAL15", "Jonathan Williams", "Wales", "-"),
			Figurinha(174, "WAL16", "Harry Wilson", "Wales", "-"),
			Figurinha(175, "WAL17", "Gareth Bale", "Wales", "-"),
			Figurinha(176, "WAL18", "Daniel James", "Wales", "-"),
			Figurinha(177, "WAL19", "Brennan Johnson", "Wales", "-"),
			Figurinha(178, "WAL20", "Kieffer Moore", "Wales", "-"),
			Figurinha(179, "ARG1", "Team Shot", "Argentina", "-"),
			Figurinha(180, "ARG2", "Team Logo", "Argentina", "foil"),
			Figurinha(181, "ARG3", "Emiliano Mart�nez", "Argentina", "-"),
			Figurinha(182, "ARG4", "Franco Armani", "Argentina", "-"),
			Figurinha(183, "ARG5", "Marcos Acu�a", "Argentina", "-"),
			Figurinha(184, "ARG6", "Nahuel Molina", "Argentina", "-"),
			Figurinha(185, "ARG7", "Nicol�s Otamendi", "Argentina", "-"),
			Figurinha(186, "ARG8", "Germ�n Pezzella", "Argentina", "-"),
			Figurinha(187, "ARG9", "Cristian Romero", "Argentina", "-"),
			Figurinha(188, "ARG10", "Rodrigo De Paul", "Argentina", "-"),
			Figurinha(189, "ARG11", "�ngel Di Mar�a", "Argentina", "-"),
			Figurinha(190, "ARG12", "Giovani Lo Celso", "Argentina", "-"),
			Figurinha(191, "ARG13", "Leandro Paredes", "Argentina", "-"),
			Figurinha(192, "ARG14", "Guido Rodr�guez", "Argentina", "-"),
			Figurinha(193, "ARG15", "Juli�n �lvarez", "Argentina", "-"),
			Figurinha(194, "ARG16", "Joaqu�n Correa", "Argentina", "-"),
			Figurinha(195, "ARG17", "Alejandro G�mez", "Argentina", "-"),
			Figurinha(196, "ARG18", "Nicol�s Gonz�lez", "Argentina", "-"),
			Figurinha(197, "ARG19", "Lautaro Mart�nez", "Argentina", "-"),
			Figurinha(198, "ARG20", "Lionel Messi", "Argentina", "-"),
			Figurinha(199, "KSA1", "Team Shot", "Saudi Arabia", "-"),
			Figurinha(200, "KSA2", "Team Logo", "Saudi Arabia", "foil"),
			Figurinha(201, "KSA3", "Mohammed Al-Owais", "Saudi Arabia", "-"),
			Figurinha(202, "KSA4", "Mohammed Al-Rubaie", "Saudi Arabia", "-"),
			Figurinha(203, "KSA5", "Abdulelah Al-Amri", "Saudi Arabia", "-"),
			Figurinha(204, "KSA6", "Ali Al-Boleahi", "Saudi Arabia", "-"),
			Figurinha(205, "KSA7", "Mohammed Al-Burayk", "Saudi Arabia", "-"),
			Figurinha(206, "KSA8", "Sultan Al-Ghannam", "Saudi Arabia", "-"),
			Figurinha(207, "KSA9", "Yasser Al-Shahrani", "Saudi Arabia", "-"),
			Figurinha(208, "KSA10", "Hassan Al-Tambakti", "Saudi Arabia", "-"),
			Figurinha(209, "KSA11", "Abdullah Madu", "Saudi Arabia", "-"),
			Figurinha(210, "KSA12", "Salman Al-Faraj", "Saudi Arabia", "-"),
			Figurinha(211, "KSA13", "Abdulelah Al-Malki", "Saudi Arabia", "-"),
			Figurinha(212, "KSA14", "Sami Al-Najei", "Saudi Arabia", "-"),
			Figurinha(213, "KSA15", "Hattan Bahebri", "Saudi Arabia", "-"),
			Figurinha(214, "KSA16", "Mohamed Kanno", "Saudi Arabia", "-"),
			Figurinha(215, "KSA17", "Abdullah Otayf", "Saudi Arabia", "-"),
			Figurinha(216, "KSA18", "Firas Al-Buraikan", "Saudi Arabia", "-"),
			Figurinha(217, "KSA19", "Salem Al-Dawsari", "Saudi Arabia", "-"),
			Figurinha(218, "KSA20", "Khalid Al-Ghannam", "Saudi Arabia", "-"),
			Figurinha(219, "MEX1", "Team Shot", "Mexico", "-"),
			Figurinha(220, "MEX2", "Team Logo", "Mexico", "foil"),
			Figurinha(221, "MEX3", "Guillermo Ochoa", "Mexico", "-"),
			Figurinha(222, "MEX4", "Alfredo Talavera", "Mexico", "-"),
			Figurinha(223, "MEX5", "N�stor Ara�jo", "Mexico", "-"),
			Figurinha(224, "MEX6", "Jes�s Gallardo", "Mexico", "-"),
			Figurinha(225, "MEX7", "C�sar Montes", "Mexico", "-"),
			Figurinha(226, "MEX8", "H�ctor Moreno", "Mexico", "-"),
			Figurinha(227, "MEX9", "Luis Romo", "Mexico", "-"),
			Figurinha(228, "MEX10", "Jorge S�nchez", "Mexico", "-"),
			Figurinha(229, "MEX11", "Edson �lvarez", "Mexico", "-"),
			Figurinha(230, "MEX12", "Jes�s Manuel Corona", "Mexico", "-"),
			Figurinha(231, "MEX13", "Andr�s Guardado", "Mexico", "-"),
			Figurinha(232, "MEX14", "�rick Guti�rrez", "Mexico", "-"),
			Figurinha(233, "MEX15", "H�ctor Herrera", "Mexico", "-"),
			Figurinha(234, "MEX16", "Diego Lainez", "Mexico", "-"),
			Figurinha(235, "MEX17", "Carlos Rodr�guez", "Mexico", "-"),
			Figurinha(236, "MEX18", "Rogelio Funes Mori", "Mexico", "-"),
			Figurinha(237, "MEX19", "Ra�l Jim�nez", "Mexico", "-"),
			Figurinha(238, "MEX20", "Hirving Lozano", "Mexico", "-"),
			Figurinha(239, "POL1", "Team Shot", "Poland", "-"),
			Figurinha(240, "POL2", "Team Logo", "Poland", "foil"),
			Figurinha(241, "POL3", "Wojciech Szczesny", "Poland", "-"),
			Figurinha(242, "POL4", "Lukasz Skorupski", "Poland", "-"),
			Figurinha(243, "POL5", "Jan Bednarek", "Poland", "-"),
			Figurinha(244, "POL6", "Bartosz Bereszynski", "Poland", "-"),
			Figurinha(245, "POL7", "Matty Cash", "Poland", "-"),
			Figurinha(246, "POL8", "Kamil Glik", "Poland", "-"),
			Figurinha(247, "POL9", "Tymoteusz Puchacz", "Poland", "-"),
			Figurinha(248, "POL10", "Maciej Rybus", "Poland", "-"),
			Figurinha(249, "POL11", "Kamil J�zwiak", "Poland", "-"),
			Figurinha(250, "POL12", "Mateusz Klich", "Poland", "-"),
			Figurinha(251, "POL13", "Grzegorz Krychowiak", "Poland", "-"),
			Figurinha(252, "POL14", "Jakub Moder", "Poland", "-"),
			Figurinha(253, "POL15", "Sebastian Szymanski", "Poland", "-"),
			Figurinha(254, "POL16", "Piotr Zielinski", "Poland", "-"),
			Figurinha(255, "POL17", "Robert Lewandowski", "Poland", "-"),
			Figurinha(256, "POL18", "Arkadiusz Milik", "Poland", "-"),
			Figurinha(257, "POL19", "Krzysztof Piatek", "Poland", "-"),
			Figurinha(258, "POL20", "Karol Swiderski", "Poland", "-"),
			Figurinha(259, "FRA1", "Team Shot", "France", "-"),
			Figurinha(260, "FRA2", "Team Logo", "France", "foil"),
			Figurinha(261, "FRA3", "Hugo Lloris", "France", "-"),
			Figurinha(262, "FRA4", "Mike Maignan", "France", "-"),
			Figurinha(263, "FRA5", "Lucas Hern�ndez", "France", "-"),
			Figurinha(264, "FRA6", "Theo Hern�ndez", "France", "-"),
			Figurinha(265, "FRA7", "Presnel Kimpembe", "France", "-"),
			Figurinha(266, "FRA8", "Jules Kound�", "France", "-"),
			Figurinha(267, "FRA9", "Benjamin Pavard", "France", "-"),
			Figurinha(268, "FRA10", "Rapha�l Varane", "France", "-"),
			Figurinha(269, "FRA11", "N�Golo Kant�", "France", "-"),
			Figurinha(270, "FRA12", "Paul Pogba", "France", "-"),
			Figurinha(271, "FRA13", "Adrien Rabiot", "France", "-"),
			Figurinha(272, "FRA14", "Aur�lien Tchouam�ni", "France", "-"),
			Figurinha(273, "FRA15", "Wissam Ben Yedder", "France", "-"),
			Figurinha(274, "FRA16", "Karim Benzema", "France", "-"),
			Figurinha(275, "FRA17", "Kingsley Coman", "France", "-"),
			Figurinha(276, "FRA18", "Antoine Griezmann", "France", "-"),
			Figurinha(277, "FRA19", "Kylian Mbapp�", "France", "-"),
			Figurinha(278, "FRA20", "Christopher Nkunku", "France", "-"),
			Figurinha(279, "AUS1", "Team Shot", "Australia", "-"),
			Figurinha(280, "AUS2", "Team Logo", "Australia", "foil"),
			Figurinha(281, "AUS3", "Mathew Ryan", "Australia", "-"),
			Figurinha(282, "AUS4", "Andrew Redmayne", "Australia", "-"),
			Figurinha(283, "AUS5", "Aziz Behich", "Australia", "-"),
			Figurinha(284, "AUS6", "Milo� Degenek", "Australia", "-"),
			Figurinha(285, "AUS7", "Rhyan Grant", "Australia", "-"),
			Figurinha(286, "AUS8", "Joel King", "Australia", "-"),
			Figurinha(287, "AUS9", "Trent Sainsbury", "Australia", "-"),
			Figurinha(288, "AUS10", "Harry Souttar", "Australia", "-"),
			Figurinha(289, "AUS11", "Ajdin Hrustic", "Australia", "-"),
			Figurinha(290, "AUS12", "Jackson Irvine", "Australia", "-"),
			Figurinha(291, "AUS13", "James Jeggo", "Australia", "-"),
			Figurinha(292, "AUS14", "Awer Mabil", "Australia", "-"),
			Figurinha(293, "AUS15", "Aaron Mooy", "Australia", "-"),
			Figurinha(294, "AUS16", "Martin Boyle", "Australia", "-"),
			Figurinha(295, "AUS17", "Mitchell Duke", "Australia", "-"),
			Figurinha(296, "AUS18", "Craig Goodwin", "Australia", "-"),
			Figurinha(297, "AUS19", "Mathew Leckie", "Australia", "-"),
			Figurinha(298, "AUS20", "Adam Taggart", "Australia", "-"),
			Figurinha(299, "DEN1", "Team Shot", "Denmark", "-"),
			Figurinha(300, "DEN2", "Team Logo", "Denmark", "foil"),
			Figurinha(301, "DEN3", "Kasper Schmeichel", "Denmark", "-"),
			Figurinha(302, "DEN4", "Frederik R�nnow", "Denmark", "-"),
			Figurinha(303, "DEN5", "Andreas Christensen", "Denmark", "-"),
			Figurinha(304, "DEN6", "Simon Kj�r", "Denmark", "-"),
			Figurinha(305, "DEN7", "Joakim M�hle", "Denmark", "-"),
			Figurinha(306, "DEN8", "Jens Stryger Larsen", "Denmark", "-"),
			Figurinha(307, "DEN9", "Jannik Vestergaard", "Denmark", "-"),
			Figurinha(308, "DEN10", "Mikkel Damsgaard", "Denmark", "-"),
			Figurinha(309, "DEN11", "Thomas Delaney", "Denmark", "-"),
			Figurinha(310, "DEN12", "Christian Eriksen", "Denmark", "-"),
			Figurinha(311, "DEN13", "Pierre Emile H�jbjerg", "Denmark", "-"),
			Figurinha(312, "DEN14", "Christian N�rgaard", "Denmark", "-"),
			Figurinha(313, "DEN15", "Daniel Wass", "Denmark", "-"),
			Figurinha(314, "DEN16", "Martin Braithwaite", "Denmark", "-"),
			Figurinha(315, "DEN17", "Kasper Dolberg", "Denmark", "-"),
			Figurinha(316, "DEN18", "Yussuf Poulsen", "Denmark", "-"),
			Figurinha(317, "DEN19", "Andreas Skov Olsen", "Denmark", "-"),
			Figurinha(318, "DEN20", "Jonas Wind", "Denmark", "-"),
			Figurinha(319, "TUN1", "Team Shot", "Tunisia", "-"),
			Figurinha(320, "TUN2", "Team Logo", "Tunisia", "foil"),
			Figurinha(321, "TUN3", "Bechir Ben Sa�d", "Tunisia", "-"),
			Figurinha(322, "TUN4", "Farouk Ben Mustapha", "Tunisia", "-"),
			Figurinha(323, "TUN5", "Dylan Bronn", "Tunisia", "-"),
			Figurinha(324, "TUN6", "Mohamed Dr�ger", "Tunisia", "-"),
			Figurinha(325, "TUN7", "Bilel Ifa", "Tunisia", "-"),
			Figurinha(326, "TUN8", "Ali Ma�loul", "Tunisia", "-"),
			Figurinha(327, "TUN9", "Hamza Mathlouthi", "Tunisia", "-"),
			Figurinha(328, "TUN10", "Yassine Meriah", "Tunisia", "-"),
			Figurinha(329, "TUN11", "Montassar Talbi", "Tunisia", "-"),
			Figurinha(330, "TUN12", "Mohamed Ali Ben Romdhane", "Tunisia", "-"),
			Figurinha(331, "TUN13", "Wahbi Khazri", "Tunisia", "-"),
			Figurinha(332, "TUN14", "A�ssa La�douni", "Tunisia", "-"),
			Figurinha(333, "TUN15", "Ferjani Sassi", "Tunisia", "-"),
			Figurinha(334, "TUN16", "Ellyes Skhiri", "Tunisia", "-"),
			Figurinha(335, "TUN17", "Anis Slimane", "Tunisia", "-"),
			Figurinha(336, "TUN18", "Seifeddine Jaziri", "Tunisia", "-"),
			Figurinha(337, "TUN19", "Youssef Msakni", "Tunisia", "-"),
			Figurinha(338, "TUN20", "Na�m Sliti", "Tunisia", "-"),
			Figurinha(339, "ESP1", "Team Shot", "Spain", "-"),
			Figurinha(340, "ESP2", "Team Logo", "Spain", "foil"),
			Figurinha(341, "ESP3", "Unai Sim�n", "Spain", "-"),
			Figurinha(342, "ESP4", "Robert S�nchez", "Spain", "-"),
			Figurinha(343, "ESP5", "C�sar Azpilicueta", "Spain", "-"),
			Figurinha(344, "ESP6", "Eric Garc�a", "Spain", "-"),
			Figurinha(345, "ESP7", "Jordi Alba", "Spain", "-"),
			Figurinha(346, "ESP8", "Aymeric Laporte", "Spain", "-"),
			Figurinha(347, "ESP9", "Pau Torres", "Spain", "-"),
			Figurinha(348, "ESP10", "Gavi", "Spain", "-"),
			Figurinha(349, "ESP11", "Koke", "Spain", "-"),
			Figurinha(350, "ESP12", "Marcos Llorente", "Spain", "-"),
			Figurinha(351, "ESP13", "Pedri", "Spain", "-"),
			Figurinha(352, "ESP14", "Rodri", "Spain", "-"),
			Figurinha(353, "ESP15", "Sergio Busquets", "Spain", "-"),
			Figurinha(354, "ESP16", "Dani Olmo", "Spain", "-"),
			Figurinha(355, "ESP17", "Ansu Fati", "Spain", "-"),
			Figurinha(356, "ESP18", "Ferran Torres", "Spain", "-"),
			Figurinha(357, "ESP19", "�lvaro Morata", "Spain", "-"),
			Figurinha(358, "ESP20", "Pablo Sarabia", "Spain", "-"),
			Figurinha(359, "CRC1", "Team Shot", "Costa Rica", "-"),
			Figurinha(360, "CRC2", "Team Logo", "Costa Rica", "foil"),
			Figurinha(361, "CRC3", "Keylor Navas", "Costa Rica", "-"),
			Figurinha(362, "CRC4", "Leonel Moreira", "Costa Rica", "-"),
			Figurinha(363, "CRC5", "Ricardo Blanco", "Costa Rica", "-"),
			Figurinha(364, "CRC6", "Francisco Calvo", "Costa Rica", "-"),
			Figurinha(365, "CRC7", "�scar Duarte", "Costa Rica", "-"),
			Figurinha(366, "CRC8", "Keysher Fuller", "Costa Rica", "-"),
			Figurinha(367, "CRC9", "Bryan Oviedo", "Costa Rica", "-"),
			Figurinha(368, "CRC10", "Juan Pablo Vargas", "Costa Rica", "-"),
			Figurinha(369, "CRC11", "Kendall Waston", "Costa Rica", "-"),
			Figurinha(370, "CRC12", "Celso Borges", "Costa Rica", "-"),
			Figurinha(371, "CRC13", "Orlando Galo", "Costa Rica", "-"),
			Figurinha(372, "CRC14", "Bryan Ruiz", "Costa Rica", "-"),
			Figurinha(373, "CRC15", "Yeltsin Tejeda", "Costa Rica", "-"),
			Figurinha(374, "CRC16", "Jewison Bennette", "Costa Rica", "-"),
			Figurinha(375, "CRC17", "Joel Campbell", "Costa Rica", "-"),
			Figurinha(376, "CRC18", "Anthony Contreras", "Costa Rica", "-"),
			Figurinha(377, "CRC19", "Gerson Torres", "Costa Rica", "-"),
			Figurinha(378, "CRC20", "Johan Venegas", "Costa Rica", "-"),
			Figurinha(379, "GER1", "Team Shot", "Germany", "-"),
			Figurinha(380, "GER2", "Team Logo", "Germany", "foil"),
			Figurinha(381, "GER3", "Manuel Neuer", "Germany", "-"),
			Figurinha(382, "GER4", "Marc-Andr� ter Stegen", "Germany", "-"),
			Figurinha(383, "GER5", "Matthias Ginter", "Germany", "-"),
			Figurinha(384, "GER6", "Robin Gosens", "Germany", "-"),
			Figurinha(385, "GER7", "Thilo Kehrer", "Germany", "-"),
			Figurinha(386, "GER8", "David Raum", "Germany", "-"),
			Figurinha(387, "GER9", "Antonio R�diger", "Germany", "-"),
			Figurinha(388, "GER10", "Niklas S�le", "Germany", "-"),
			Figurinha(389, "GER11", "Leon Goretzka", "Germany", "-"),
			Figurinha(390, "GER12", "Ilkay G�ndogan", "Germany", "-"),
			Figurinha(391, "GER13", "Kai Havertz", "Germany", "-"),
			Figurinha(392, "GER14", "Jonas Hofmann", "Germany", "-"),
			Figurinha(393, "GER15", "Joshua Kimmich", "Germany", "-"),
			Figurinha(394, "GER16", "Serge Gnabry", "Germany", "-"),
			Figurinha(395, "GER17", "Thomas M�ller", "Germany", "-"),
			Figurinha(396, "GER18", "Marco Reus", "Germany", "-"),
			Figurinha(397, "GER19", "Leroy San�", "Germany", "-"),
			Figurinha(398, "GER20", "Timo Werner", "Germany", "-"),
			Figurinha(399, "JPN1", "Team Shot", "Japan", "-"),
			Figurinha(400, "JPN2", "Team Logo", "Japan", "foil"),
			Figurinha(401, "JPN3", "Shuichi Gonda", "Japan", "-"),
			Figurinha(402, "JPN4", "Eiji Kawashima", "Japan", "-"),
			Figurinha(403, "JPN5", "Yuto Nagatomo", "Japan", "-"),
			Figurinha(404, "JPN6", "Yuta Nakayama", "Japan", "-"),
			Figurinha(405, "JPN7", "Takehiro Tomiyasu", "Japan", "-"),
			Figurinha(406, "JPN8", "Miki Yamane", "Japan", "-"),
			Figurinha(407, "JPN9", "Maya Yoshida", "Japan", "-"),
			Figurinha(408, "JPN10", "Wataru Endo", "Japan", "-"),
			Figurinha(409, "JPN11", "Genki Haraguchi", "Japan", "-"),
			Figurinha(410, "JPN12", "Hidemasa Morita", "Japan", "-"),
			Figurinha(411, "JPN13", "Gaku Shibasaki", "Japan", "-"),
			Figurinha(412, "JPN14", "Ao Tanaka", "Japan", "-"),
			Figurinha(413, "JPN15", "Takuma Asano", "Japan", "-"),
			Figurinha(414, "JPN16", "Kyogo Furuhashi", "Japan", "-"),
			Figurinha(415, "JPN17", "Junya Ito", "Japan", "-"),
			Figurinha(416, "JPN18", "Takumi Minamino", "Japan", "-"),
			Figurinha(417, "JPN19", "Kaoru Mitoma", "Japan", "-"),
			Figurinha(418, "JPN20", "Yuya Osako", "Japan", "-"),
			Figurinha(419, "BEL1", "Team Shot", "Belgium", "-"),
			Figurinha(420, "BEL2", "Team Logo", "Belgium", "foil"),
			Figurinha(421, "BEL3", "Thibaut Courtois", "Belgium", "-"),
			Figurinha(422, "BEL4", "Simon Mignolet", "Belgium", "-"),
			Figurinha(423, "BEL5", "Toby Alderweireld", "Belgium", "-"),
			Figurinha(424, "BEL6", "Timothy Castagne", "Belgium", "-"),
			Figurinha(425, "BEL7", "Jason Denayer", "Belgium", "-"),
			Figurinha(426, "BEL8", "Thomas Meunier", "Belgium", "-"),
			Figurinha(427, "BEL9", "Jan Vertonghen", "Belgium", "-"),
			Figurinha(428, "BEL10", "Yannick Carrasco", "Belgium", "-"),
			Figurinha(429, "BEL11", "Kevin De Bruyne", "Belgium", "-"),
			Figurinha(430, "BEL12", "Charles De Ketelaere", "Belgium", "-"),
			Figurinha(431, "BEL13", "Thorgan Hazard", "Belgium", "-"),
			Figurinha(432, "BEL14", "Youri Tielemans", "Belgium", "-"),
			Figurinha(433, "BEL15", "Hans Vanaken", "Belgium", "-"),
			Figurinha(434, "BEL16", "Axel Witsel", "Belgium", "-"),
			Figurinha(435, "BEL17", "J�r�my Doku", "Belgium", "-"),
			Figurinha(436, "BEL18", "Eden Hazard", "Belgium", "-"),
			Figurinha(437, "BEL19", "Romelu Lukaku", "Belgium", "-"),
			Figurinha(438, "BEL20", "Dries Mertens", "Belgium", "-"),
			Figurinha(439, "CAN1", "Team Shot", "Canada", "-"),
			Figurinha(440, "CAN2", "Team Logo", "Canada", "foil"),
			Figurinha(441, "CAN3", "Milan Borjan", "Canada", "-"),
			Figurinha(442, "CAN4", "Maxime Cr�peau", "Canada", "-"),
			Figurinha(443, "CAN5", "Samuel Adekugbe", "Canada", "-"),
			Figurinha(444, "CAN6", "Doneil Henry", "Canada", "-"),
			Figurinha(445, "CAN7", "Alistair Johnston", "Canada", "-"),
			Figurinha(446, "CAN8", "Richie Laryea", "Canada", "-"),
			Figurinha(447, "CAN9", "Kamal Miller", "Canada", "-"),
			Figurinha(448, "CAN10", "Steven Vit�ria", "Canada", "-"),
			Figurinha(449, "CAN11", "Tajon Buchanan", "Canada", "-"),
			Figurinha(450, "CAN12", "Alphonso Davies", "Canada", "-"),
			Figurinha(451, "CAN13", "Stephen Eust�quio", "Canada", "-"),
			Figurinha(452, "CAN14", "Atiba Hutchinson", "Canada", "-"),
			Figurinha(453, "CAN15", "Mark-Anthony Kaye", "Canada", "-"),
			Figurinha(454, "CAN16", "Jonathan Osorio", "Canada", "-"),
			Figurinha(455, "CAN17", "Samuel Piette", "Canada", "-"),
			Figurinha(456, "CAN18", "Jonathan David", "Canada", "-"),
			Figurinha(457, "CAN19", "David Junior Hoilett", "Canada", "-"),
			Figurinha(458, "CAN20", "Cyle Larin", "Canada", "-"),
			Figurinha(459, "MAR1", "Team Shot", "Morocco", "-"),
			Figurinha(460, "MAR2", "Team Logo", "Morocco", "foil"),
			Figurinha(461, "MAR3", "Yassine Bounou", "Morocco", "-"),
			Figurinha(462, "MAR4", "Munir Mohamedi", "Morocco", "-"),
			Figurinha(463, "MAR5", "Nayef Aguerd", "Morocco", "-"),
			Figurinha(464, "MAR6", "Achraf Hakimi", "Morocco", "-"),
			Figurinha(465, "MAR7", "Adam Masina", "Morocco", "-"),
			Figurinha(466, "MAR8", "Samy Mmaee", "Morocco", "-"),
			Figurinha(467, "MAR9", "Romain Sa�ss", "Morocco", "-"),
			Figurinha(468, "MAR10", "Selim Amallah", "Morocco", "-"),
			Figurinha(469, "MAR11", "Sofyan Amrabat", "Morocco", "-"),
			Figurinha(470, "MAR12", "Aymen Barkok", "Morocco", "-"),
			Figurinha(471, "MAR13", "Ilias Chair", "Morocco", "-"),
			Figurinha(472, "MAR14", "Imr�n Louza", "Morocco", "-"),
			Figurinha(473, "MAR15", "Sofiane Boufal", "Morocco", "-"),
			Figurinha(474, "MAR16", "Ayoub El Kaabi", "Morocco", "-"),
			Figurinha(475, "MAR17", "Youssef En-Nesyri", "Morocco", "-"),
			Figurinha(476, "MAR18", "Ryan Mmaee", "Morocco", "-"),
			Figurinha(477, "MAR19", "Munir", "Morocco", "-"),
			Figurinha(478, "MAR20", "Tarik Tissoudali", "Morocco", "-"),
			Figurinha(479, "CRO1", "Team Shot", "Croatia", "-"),
			Figurinha(480, "CRO2", "Team Logo", "Croatia", "foil"),
			Figurinha(481, "CRO3", "Dominik Livakovic", "Croatia", "-"),
			Figurinha(482, "CRO4", "Ivica Ivu�ic", "Croatia", "-"),
			Figurinha(483, "CRO5", "Duje Caleta-Car", "Croatia", "-"),
			Figurinha(484, "CRO6", "Jo�ko Gvardiol", "Croatia", "-"),
			Figurinha(485, "CRO7", "Josip Juranovic", "Croatia", "-"),
			Figurinha(486, "CRO8", "Dejan Lovren", "Croatia", "-"),
			Figurinha(487, "CRO9", "Borna Sosa", "Croatia", "-"),
			Figurinha(488, "CRO10", "Domagoj Vida", "Croatia", "-"),
			Figurinha(489, "CRO11", "Marcelo Brozovic", "Croatia", "-"),
			Figurinha(490, "CRO12", "Mateo Kovacic", "Croatia", "-"),
			Figurinha(491, "CRO13", "Luka Modric", "Croatia", "-"),
			Figurinha(492, "CRO14", "Mario Pa�alic", "Croatia", "-"),
			Figurinha(493, "CRO15", "Ivan Peri�ic", "Croatia", "-"),
			Figurinha(494, "CRO16", "Nikola Vla�ic", "Croatia", "-"),
			Figurinha(495, "CRO17", "Josip Brekalo", "Croatia", "-"),
			Figurinha(496, "CRO18", "Andrej Kramaric", "Croatia", "-"),
			Figurinha(497, "CRO19", "Marko Livaja", "Croatia", "-"),
			Figurinha(498, "CRO20", "Mislav Or�ic", "Croatia", "-"),
			Figurinha(499, "BRA1", "Team Shot", "Brazil", "-"),
			Figurinha(500, "BRA2", "Team Logo", "Brazil", "foil"),
			Figurinha(501, "BRA3", "Alisson", "Brazil", "-"),
			Figurinha(502, "BRA4", "Ederson", "Brazil", "-"),
			Figurinha(503, "BRA5", "Alex Sandro", "Brazil", "-"),
			Figurinha(504, "BRA6", "Danilo", "Brazil", "-"),
			Figurinha(505, "BRA7", "�der Milit�o", "Brazil", "-"),
			Figurinha(506, "BRA8", "Marquinhos", "Brazil", "-"),
			Figurinha(507, "BRA9", "Thiago Silva", "Brazil", "-"),
			Figurinha(508, "BRA10", "Casemiro", "Brazil", "-"),
			Figurinha(509, "BRA11", "Philippe Coutinho", "Brazil", "-"),
			Figurinha(510, "BRA12", "Fabinho", "Brazil", "-"),
			Figurinha(511, "BRA13", "Fred", "Brazil", "-"),
			Figurinha(512, "BRA14", "Lucas Paquet�", "Brazil", "-"),
			Figurinha(513, "BRA15", "Antony", "Brazil", "-"),
			Figurinha(514, "BRA16", "Gabriel Jesus", "Brazil", "-"),
			Figurinha(515, "BRA17", "Neymar Jr", "Brazil", "-"),
			Figurinha(516, "BRA18", "Raphinha", "Brazil", "-"),
			Figurinha(517, "BRA19", "Richarlison", "Brazil", "-"),
			Figurinha(518, "BRA20", "Vin�cius Jr", "Brazil", "-"),
			Figurinha(519, "SRB1", "Team Shot", "Serbia", "-"),
			Figurinha(520, "SRB2", "Team Logo", "Serbia", "foil"),
			Figurinha(521, "SRB3", "Predrag Rajkovic", "Serbia", "-"),
			Figurinha(522, "SRB4", "Vanja Milinkovic-Savic", "Serbia", "-"),
			Figurinha(523, "SRB5", "Nikola Milenkovic", "Serbia", "-"),
			Figurinha(524, "SRB6", "Strahinja Pavlovic", "Serbia", "-"),
			Figurinha(525, "SRB7", "Milo� Veljkovic", "Serbia", "-"),
			Figurinha(526, "SRB8", "Filip �uricic", "Serbia", "-"),
			Figurinha(527, "SRB9", "Nemanja Gudelj", "Serbia", "-"),
			Figurinha(528, "SRB10", "Filip Kostic", "Serbia", "-"),
			Figurinha(529, "SRB11", "Darko Lazovic", "Serbia", "-"),
			Figurinha(530, "SRB12", "Sa�a Lukic", "Serbia", "-"),
			Figurinha(531, "SRB13", "Nemanja Maksimovic", "Serbia", "-"),
			Figurinha(532, "SRB14", "Sergej Milinkovic-Savic", "Serbia", "-"),
			Figurinha(533, "SRB15", "Nemanja Radonjic", "Serbia", "-"),
			Figurinha(534, "SRB16", "Andrija �ivkovic", "Serbia", "-"),
			Figurinha(535, "SRB17", "Luka Jovic", "Serbia", "-"),
			Figurinha(536, "SRB18", "Aleksandar Mitrovic", "Serbia", "-"),
			Figurinha(537, "SRB19", "Du�an Tadic", "Serbia", "-"),
			Figurinha(538, "SRB20", "Du�an Vlahovic", "Serbia", "-"),
			Figurinha(539, "SUI1", "Team Shot", "Switzerland", "-"),
			Figurinha(540, "SUI2", "Team Logo", "Switzerland", "foil"),
			Figurinha(541, "SUI3", "Yann Sommer", "Switzerland", "-"),
			Figurinha(542, "SUI4", "Gregor Kobel", "Switzerland", "-"),
			Figurinha(543, "SUI5", "Manuel Akanji", "Switzerland", "-"),
			Figurinha(544, "SUI6", "Nico Elvedi", "Switzerland", "-"),
			Figurinha(545, "SUI7", "Kevin Mbabu", "Switzerland", "-"),
			Figurinha(546, "SUI8", "Ricardo Rodr�guez", "Switzerland", "-"),
			Figurinha(547, "SUI9", "Fabian Sch�r", "Switzerland", "-"),
			Figurinha(548, "SUI10", "Silvan Widmer", "Switzerland", "-"),
			Figurinha(549, "SUI11", "Remo Freuler", "Switzerland", "-"),
			Figurinha(550, "SUI12", "Xherdan Shaqiri", "Switzerland", "-"),
			Figurinha(551, "SUI13", "Djibril Sow", "Switzerland", "-"),
			Figurinha(552, "SUI14", "Granit Xhaka", "Switzerland", "-"),
			Figurinha(553, "SUI15", "Denis Zakaria", "Switzerland", "-"),
			Figurinha(554, "SUI16", "Steven Zuber", "Switzerland", "-"),
			Figurinha(555, "SUI17", "Breel Embolo", "Switzerland", "-"),
			Figurinha(556, "SUI18", "Noah Okafor", "Switzerland", "-"),
			Figurinha(557, "SUI19", "Haris Seferovic", "Switzerland", "-"),
			Figurinha(558, "SUI20", "Ruben Vargas", "Switzerland", "-"),
			Figurinha(559, "CMR1", "Team Shot", "Cameroon", "-"),
			Figurinha(560, "CMR2", "Team Logo", "Cameroon", "foil"),
			Figurinha(561, "CMR3", "Andr� Onana", "Cameroon", "-"),
			Figurinha(562, "CMR4", "Devis Epassy", "Cameroon", "-"),
			Figurinha(563, "CMR5", "Jean-Charles Castelletto", "Cameroon", "-"),
			Figurinha(564, "CMR6", "Collins Fai", "Cameroon", "-"),
			Figurinha(565, "CMR7", "Olivier Mbaizo", "Cameroon", "-"),
			Figurinha(566, "CMR8", "Harold Moukoudi", "Cameroon", "-"),
			Figurinha(567, "CMR9", "Michael Ngadeu", "Cameroon", "-"),
			Figurinha(568, "CMR10", "Nouhou", "Cameroon", "-"),
			Figurinha(569, "CMR11", "Martin Hongla", "Cameroon", "-"),
			Figurinha(570, "CMR12", "Pierre Kunde", "Cameroon", "-"),
			Figurinha(571, "CMR13", "James L�a Siliki", "Cameroon", "-"),
			Figurinha(572, "CMR14", "Samuel Oum Gouet", "Cameroon", "-"),
			Figurinha(573, "CMR15", "Andr�-Frank Zambo Anguissa", "Cameroon", "-"),
			Figurinha(574, "CMR16", "Vincent Aboubakar", "Cameroon", "-"),
			Figurinha(575, "CMR17", "St�phane Bahoken", "Cameroon", "-"),
			Figurinha(576, "CMR18", "Eric Maxim Choupo-Moting", "Cameroon", "-"),
			Figurinha(577, "CMR19", "Nicolas Moumi Ngamaleu", "Cameroon", "-"),
			Figurinha(578, "CMR20", "Karl Toko Ekambi", "Cameroon", "-"),
			Figurinha(579, "POR1", "Team Shot", "Portugal", "-"),
			Figurinha(580, "POR2", "Team Logo", "Portugal", "foil"),
			Figurinha(581, "POR3", "Diogo Costa", "Portugal", "-"),
			Figurinha(582, "POR4", "Rui Patr�cio", "Portugal", "-"),
			Figurinha(583, "POR5", "Jo�o Cancelo", "Portugal", "-"),
			Figurinha(584, "POR6", "Jos� Fonte", "Portugal", "-"),
			Figurinha(585, "POR7", "Nuno Mendes", "Portugal", "-"),
			Figurinha(586, "POR8", "Pepe", "Portugal", "-"),
			Figurinha(587, "POR9", "Rapha�l Guerreiro", "Portugal", "-"),
			Figurinha(588, "POR10", "R�ben Dias", "Portugal", "-"),
			Figurinha(589, "POR11", "Bernardo Silva", "Portugal", "-"),
			Figurinha(590, "POR12", "Bruno Fernandes", "Portugal", "-"),
			Figurinha(591, "POR13", "Danilo Pereira", "Portugal", "-"),
			Figurinha(592, "POR14", "Jo�o Moutinho", "Portugal", "-"),
			Figurinha(593, "POR15", "Renato Sanches", "Portugal", "-"),
			Figurinha(594, "POR16", "R�ben Neves", "Portugal", "-"),
			Figurinha(595, "POR17", "Andr� Silva", "Portugal", "-"),
			Figurinha(596, "POR18", "Cristiano Ronaldo", "Portugal", "-"),
			Figurinha(597, "POR19", "Diogo Jota", "Portugal", "-"),
			Figurinha(598, "POR20", "Gon�alo Guedes", "Portugal", "-"),
			Figurinha(599, "GHA1", "Team Shot", "Ghana", "-"),
			Figurinha(600, "GHA2", "Team Logo", "Ghana", "foil"),
			Figurinha(601, "GHA3", "Joe Wollacott", "Ghana", "-"),
			Figurinha(602, "GHA4", "Richard Ofori", "Ghana", "-"),
			Figurinha(603, "GHA5", "Daniel Amartey", "Ghana", "-"),
			Figurinha(604, "GHA6", "Abdul-Rahman Baba", "Ghana", "-"),
			Figurinha(605, "GHA7", "Alexander Djiku", "Ghana", "-"),
			Figurinha(606, "GHA8", "Gideon Mensah", "Ghana", "-"),
			Figurinha(607, "GHA9", "Jonathan Mensah", "Ghana", "-"),
			Figurinha(608, "GHA10", "Andy Yiadom", "Ghana", "-"),
			Figurinha(609, "GHA11", "Iddrisu Baba", "Ghana", "-"),
			Figurinha(610, "GHA12", "Mohammed Kudus", "Ghana", "-"),
			Figurinha(611, "GHA13", "Daniel-Kofi Kyereh", "Ghana", "-"),
			Figurinha(612, "GHA14", "Thomas Partey", "Ghana", "-"),
			Figurinha(613, "GHA15", "Mubarak Wakaso", "Ghana", "-"),
			Figurinha(614, "GHA16", "Felix Afena-Gyan", "Ghana", "-"),
			Figurinha(615, "GHA17", "Andr� Ayew", "Ghana", "-"),
			Figurinha(616, "GHA18", "Jordan Ayew", "Ghana", "-"),
			Figurinha(617, "GHA19", "Issahaku Abdul Fatawu", "Ghana", "-"),
			Figurinha(618, "GHA20", "Kamaldeen Sulemana", "Ghana", "-"),
			Figurinha(619, "URU1", "Team Shot", "Uruguay", "-"),
			Figurinha(620, "URU2", "Team Logo", "Uruguay", "foil"),
			Figurinha(621, "URU3", "Fernando Muslera", "Uruguay", "-"),
			Figurinha(622, "URU4", "Sergio Rochet", "Uruguay", "-"),
			Figurinha(623, "URU5", "Ronald Ara�jo", "Uruguay", "-"),
			Figurinha(624, "URU6", "Mart�n C�ceres", "Uruguay", "-"),
			Figurinha(625, "URU7", "Jos� Mar�a Gim�nez", "Uruguay", "-"),
			Figurinha(626, "URU8", "Diego God�n", "Uruguay", "-"),
			Figurinha(627, "URU9", "Math�as Olivera", "Uruguay", "-"),
			Figurinha(628, "URU10", "Mat�as Vi�a", "Uruguay", "-"),
			Figurinha(629, "URU11", "Rodrigo Bentancur", "Uruguay", "-"),
			Figurinha(630, "URU12", "Giorgian De Arrascaeta", "Uruguay", "-"),
			Figurinha(631, "URU13", "Nicol�s De La Cruz", "Uruguay", "-"),
			Figurinha(632, "URU14", "Lucas Torreira", "Uruguay", "-"),
			Figurinha(633, "URU15", "Federico Valverde", "Uruguay", "-"),
			Figurinha(634, "URU16", "Mat�as Vecino", "Uruguay", "-"),
			Figurinha(635, "URU17", "Edinson Cavani", "Uruguay", "-"),
			Figurinha(636, "URU18", "Darwin N��ez", "Uruguay", "-"),
			Figurinha(637, "URU19", "Facundo Pellistri", "Uruguay", "-"),
			Figurinha(638, "URU20", "Luis Su�rez", "Uruguay", "-"),
			Figurinha(639, "KOR1", "Team Shot", "Korea Republic", "-"),
			Figurinha(640, "KOR2", "Team Logo", "Korea Republic", "foil"),
			Figurinha(641, "KOR3", "Seung-gyu Kim", "Korea Republic", "-"),
			Figurinha(642, "KOR4", "Hyeon-woo Jo", "Korea Republic", "-"),
			Figurinha(643, "KOR5", "Chul Hong", "Korea Republic", "-"),
			Figurinha(644, "KOR6", "Tae-hwan Kim", "Korea Republic", "-"),
			Figurinha(645, "KOR7", "Min-jae Kim", "Korea Republic", "-"),
			Figurinha(646, "KOR8", "Young-gwon Kim", "Korea Republic", "-"),
			Figurinha(647, "KOR9", "Jin-su Kim", "Korea Republic", "-"),
			Figurinha(648, "KOR10", "Yong Lee", "Korea Republic", "-"),
			Figurinha(649, "KOR11", "In-beom Hwang", "Korea Republic", "-"),
			Figurinha(650, "KOR12", "Woo-young Jung", "Korea Republic", "-"),
			Figurinha(651, "KOR13", "Jae-sung Lee", "Korea Republic", "-"),
			Figurinha(652, "KOR14", "Seung-ho Paik", "Korea Republic", "-"),
			Figurinha(653, "KOR15", "Gue-sung Cho", "Korea Republic", "-"),
			Figurinha(654, "KOR16", "Hee-chan Hwang", "Korea Republic", "-"),
			Figurinha(655, "KOR17", "Ui-jo Hwang", "Korea Republic", "-"),
			Figurinha(656, "KOR18", "Chang-hoon Kwon", "Korea Republic", "-"),
			Figurinha(657, "KOR19", "Heung-min Son", "Korea Republic", "-"),
			Figurinha(658, "KOR20", "Min-kyu Song", "Korea Republic", "-"),
			Figurinha(659, "FWC19", "Uruguay 1930", "FIFA Museum", "foil"),
			Figurinha(660, "FWC20", "Italy 1938", "FIFA Museum", "foil"),
			Figurinha(661, "FWC21", "Brazil 1958", "FIFA Museum", "foil"),
			Figurinha(662, "FWC22", "England 1966", "FIFA Museum", "foil"),
			Figurinha(663, "FWC23", "Brazil 1970", "FIFA Museum", "foil"),
			Figurinha(664, "FWC24", "Argentina 1978", "FIFA Museum", "foil"),
			Figurinha(665, "FWC25", "Italy 1982", "FIFA Museum", "foil"),
			Figurinha(666, "FWC26", "Germany FR 1990", "FIFA Museum", "foil"),
			Figurinha(667, "FWC27", "France 1998", "FIFA Museum", "foil"),
			Figurinha(668, "FWC28", "Spain 2010", "FIFA Museum", "foil"),
			Figurinha(669, "FWC29", "France 2018", "FIFA Museum", "foil"),
			Figurinha(670, "C1", "Serge Gnabry (Germany)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(671, "C2", "Emiliano Mart�nez (Argentina)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(672, "C3", "Kevin De Bruyne (Belgium)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(673, "C4", "Luka Modric (Croatia)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(674, "C5", "Declan Rice (England)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(675, "C6", "Gavi (Spain)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(676, "C7", "Hirving Lozano (Mexico)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(677, "C8", "Heung-min Son (Korea Republic)", "Coca-Cola Team Believers", "Brazil extra"),
			Figurinha(678, "AA", "Almoez Ali (Qatar)", "Legend", "EXTRA"),
			Figurinha(679, "SM", "Sadio Man� (Senegal)", "Legend", "EXTRA"),
			Figurinha(680, "LM", "Lionel Messi (Argentina)", "Legend", "EXTRA"),
			Figurinha(681, "GO", "Guillermo Ochoa (Mexico)", "Legend", "EXTRA"),
			Figurinha(682, "RL", "Robert Lewandowski (Poland)", "Legend", "EXTRA"),
			Figurinha(683, "RV", "Rapha�l Varane (France)", "Legend", "EXTRA"),
			Figurinha(684, "KM", "Kylian Mbapp� (France)", "Legend", "EXTRA"),
			Figurinha(685, "CE", "Christian Eriksen (Denmark)", "Legend", "EXTRA"),
			Figurinha(686, "KDB", "Kevin De Bruyne (Belgium)", "Legend", "EXTRA"),
			Figurinha(687, "LMO", "Luka Modric (Croatia)", "Legend", "EXTRA"),
			Figurinha(688, "NJ", "Neymar Jr (Brazil)", "Legend", "EXTRA"),
			Figurinha(689, "CR", "Cristiano Ronaldo (Portugal)", "Legend", "EXTRA"),
			Figurinha(690, "LS", "Luis Su�rez (Uruguay)", "Legend", "EXTRA"),
			Figurinha(691, "HS", "Heung-min Son (Korea Republic)", "Legend", "EXTRA"),
			Figurinha(692, "RG", "Ryan Gravenberch (Netherlands)", "Rookie", "EXTRA"),
			Figurinha(693, "JB", "Jude Bellingham (England)", "Rookie", "EXTRA"),
			Figurinha(694, "GR", "Giovanni Reyna (USA)", "Rookie", "EXTRA"),
			Figurinha(695, "G", "Gavi (Spain)", "Rookie", "EXTRA"),
			Figurinha(696, "AD", "Alphonso Davies (Canada)", "Rookie", "EXTRA"),
			Figurinha(697, "DV", "Du�an Vlahovic (Serbia)", "Rookie", "EXTRA"),
			Figurinha(698, "AA-b", "Almoez Ali (Qatar)", "Legend", "EXTRA / Bronze"),
			Figurinha(699, "SM-b", "Sadio Man� (Senegal)", "Legend", "EXTRA / Bronze"),
			Figurinha(700, "LM-b", "Lionel Messi (Argentina)", "Legend", "EXTRA / Bronze"),
			Figurinha(701, "GO-b", "Guillermo Ochoa (Mexico)", "Legend", "EXTRA / Bronze"),
			Figurinha(702, "RL-b", "Robert Lewandowski (Poland)", "Legend", "EXTRA / Bronze"),
			Figurinha(703, "RV-b", "Rapha�l Varane (France)", "Legend", "EXTRA / Bronze"),
			Figurinha(704, "KM-b", "Kylian Mbapp� (France)", "Legend", "EXTRA / Bronze"),
			Figurinha(705, "CE-b", "Christian Eriksen (Denmark)", "Legend", "EXTRA / Bronze"),
			Figurinha(706, "KDB-b", "Kevin De Bruyne (Belgium)", "Legend", "EXTRA / Bronze"),
			Figurinha(707, "LMO-b", "Luka Modric (Croatia)", "Legend", "EXTRA / Bronze"),
			Figurinha(708, "NJ-b", "Neymar Jr (Brazil)", "Legend", "EXTRA / Bronze"),
			Figurinha(709, "CR-b", "Cristiano Ronaldo (Portugal)", "Legend", "EXTRA / Bronze"),
			Figurinha(710, "LS-b", "Luis Su�rez (Uruguay)", "Legend", "EXTRA / Bronze"),
			Figurinha(711, "HS-b", "Heung-min Son (Korea Republic)", "Legend", "EXTRA / Bronze"),
			Figurinha(712, "RG-b", "Ryan Gravenberch (Netherlands)", "Rookie", "EXTRA / Bronze"),
			Figurinha(713, "JB-b", "Jude Bellingham (England)", "Rookie", "EXTRA / Bronze"),
			Figurinha(714, "GR-b", "Giovanni Reyna (USA)", "Rookie", "EXTRA / Bronze"),
			Figurinha(715, "G-b", "Gavi (Spain)", "Rookie", "EXTRA / Bronze"),
			Figurinha(716, "AD-b", "Alphonso Davies (Canada)", "Rookie", "EXTRA / Bronze"),
			Figurinha(717, "DV-b", "Du�an Vlahovic (Serbia)", "Rookie", "EXTRA / Bronze"),
			Figurinha(718, "AA-s", "Almoez Ali (Qatar)", "Legend", "EXTRA / Silver"),
			Figurinha(719, "SM-s", "Sadio Man� (Senegal)", "Legend", "EXTRA / Silver"),
			Figurinha(720, "LM-s", "Lionel Messi (Argentina)", "Legend", "EXTRA / Silver"),
			Figurinha(721, "GO-s", "Guillermo Ochoa (Mexico)", "Legend", "EXTRA / Silver"),
			Figurinha(722, "RL-s", "Robert Lewandowski (Poland)", "Legend", "EXTRA / Silver"),
			Figurinha(723, "RV-s", "Rapha�l Varane (France)", "Legend", "EXTRA / Silver"),
			Figurinha(724, "KM-s", "Kylian Mbapp� (France)", "Legend", "EXTRA / Silver"),
			Figurinha(725, "CE-s", "Christian Eriksen (Denmark)", "Legend", "EXTRA / Silver"),
			Figurinha(726, "KDB-s", "Kevin De Bruyne (Belgium)", "Legend", "EXTRA / Silver"),
			Figurinha(727, "LMO-s", "Luka Modric (Croatia)", "Legend", "EXTRA / Silver"),
			Figurinha(728, "NJ-s", "Neymar Jr (Brazil)", "Legend", "EXTRA / Silver"),
			Figurinha(729, "CR-s", "Cristiano Ronaldo (Portugal)", "Legend", "EXTRA / Silver"),
			Figurinha(730, "LS-s", "Luis Su�rez (Uruguay)", "Legend", "EXTRA / Silver"),
			Figurinha(731, "HS-s", "Heung-min Son (Korea Republic)", "Legend", "EXTRA / Silver"),
			Figurinha(732, "RG-s", "Ryan Gravenberch (Netherlands)", "Rookie", "EXTRA / Silver"),
			Figurinha(733, "JB-s", "Jude Bellingham (England)", "Rookie", "EXTRA / Silver"),
			Figurinha(734, "GR-s", "Giovanni Reyna (USA)", "Rookie", "EXTRA / Silver"),
			Figurinha(735, "G-s", "Gavi (Spain)", "Rookie", "EXTRA / Silver"),
			Figurinha(736, "AD-s", "Alphonso Davies (Canada)", "Rookie", "EXTRA / Silver"),
			Figurinha(737, "DV-s", "Du�an Vlahovic (Serbia)", "Rookie", "EXTRA / Silver"),
			Figurinha(738, "AA-g", "Almoez Ali (Qatar)", "Legend", "EXTRA / Gold"),
			Figurinha(739, "SM-g", "Sadio Man� (Senegal)", "Legend", "EXTRA / Gold"),
			Figurinha(740, "LM-g", "Lionel Messi (Argentina)", "Legend", "EXTRA / Gold"),
			Figurinha(741, "GO-g", "Guillermo Ochoa (Mexico)", "Legend", "EXTRA / Gold"),
			Figurinha(742, "RL-g", "Robert Lewandowski (Poland)", "Legend", "EXTRA / Gold"),
			Figurinha(743, "RV-g", "Rapha�l Varane (France)", "Legend", "EXTRA / Gold"),
			Figurinha(744, "KM-g", "Kylian Mbapp� (France)", "Legend", "EXTRA / Gold"),
			Figurinha(745, "CE-g", "Christian Eriksen (Denmark)", "Legend", "EXTRA / Gold"),
			Figurinha(746, "KDB-g", "Kevin De Bruyne (Belgium)", "Legend", "EXTRA / Gold"),
			Figurinha(747, "LMO-g", "Luka Modric (Croatia)", "Legend", "EXTRA / Gold"),
			Figurinha(748, "NJ-g", "Neymar Jr (Brazil)", "Legend", "EXTRA / Gold"),
			Figurinha(749, "CR-g", "Cristiano Ronaldo (Portugal)", "Legend", "EXTRA / Gold"),
			Figurinha(750, "LS-g", "Luis Su�rez (Uruguay)", "Legend", "EXTRA / Gold"),
			Figurinha(751, "HS-g", "Heung-min Son (Korea Republic)", "Legend", "EXTRA / Gold"),
			Figurinha(752, "RG-g", "Ryan Gravenberch (Netherlands)", "Rookie", "EXTRA / Gold"),
			Figurinha(753, "JB-g", "Jude Bellingham (England)", "Rookie", "EXTRA / Gold"),
			Figurinha(754, "GR-g", "Giovanni Reyna (USA)", "Rookie", "EXTRA / Gold"),
			Figurinha(755, "G-g", "Gavi (Spain)", "Rookie", "EXTRA / Gold"),
			Figurinha(756, "AD-g", "Alphonso Davies (Canada)", "Rookie", "EXTRA / Gold"),
			Figurinha(757, "DV-g", "Du�an Vlahovic (Serbia)", "Rookie", "EXTRA / Gold"),
	};

	return store;
}

void printar_figurinha(Figurinha f)
{
	cout << "Id: " << f.getId() << endl
			 << "Código: " << f.getCodigo() << endl
			 << "Título: " << f.getTitulo() << endl
			 << "Seção: " << f.getSecao() << endl
			 << "Tipo: " << f.getTipo() << endl
			 << "\n";
}

int random_number()
{
	srand((unsigned)time(NULL));
	int random = rand() % 757;

	return random;
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");

	vector<Figurinha> figurinhas = initialize_data();

	string username; // nome do usuário
	int opcao;			 // armazena a escolha do usuário

	cout << "Bem-vindo(a) ao seu álbum de figurinhas da copa!" << endl;
	cout << "Qual é o seu nome? ";
	cin >> username;
	cout << "Ah! É um prazer te conhecer, " << username << "." << endl;
	cout << "Aqui você pode pedir figurinhas aleatórias ao mestre e colar\nno seu álbum ou colocar na sua coleção para trocas futuras.\n"
			 << endl;

	Album album(80, "./persistence/album.csv");
	Colecao collection("./persistence/collection.csv");

	Album *albumPtr = &album;
	Colecao *collectionPtr = &collection;
	Colecionador user(12345, username, albumPtr, collectionPtr);

	do // Interação com o usuário
	{
		cout << "Digite a opção desejada:\n"
				 << "  1 Listar figurinhas da coleção\n"
				 << "  2 Adquirir figurinha\n"
				 << "  3 Trocar figurinha\n"
				 << "  4 Listar figurinhas do álbum\n"
				 << "  5 Sair do programa\n";

		cout << "? ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
		{
			user.mostrarColecao();
			cout << "\n";
			break;
		}
		case 2:
		{
			cout << "Muito bem! Sua figurinha sorteada foi essa:\n\n";
			Figurinha sorted = figurinhas[random_number()];
			printar_figurinha(sorted);

			int option;

			cout << "Deseja colar a figurinha no Álbum ou colocar na sua coleção?" << endl
					 << "  1 Colar no Álbum." << endl
					 << "  2 Colocar na coleção." << endl;
			cout << "? ";
			cin >> option;

			switch (option)
			{
			case 1:
				user.colarFigurinhaNoAlbum(sorted);
				cout << "Ok! Sua figurinha agora está no álbum.\n"
						 << endl;
				break;

			case 2:
				user.colocarFigurinhaNaColecao(sorted);
				cout << "Ok! Sua figurinha agora está na coleção\n"
						 << endl;
				break;

			default:
				cout << "Essa não é uma opção válida." << endl;
				break;
			}
			break;
		}
		case 3:
		{
			string cartasCedidas, cartasRecebidas;
			string temp;
			vector<string> cedidas, recebidas;
			vector<Figurinha> result;

			cout << "Ok! Digite os id's separados por vírgula das figurinhas da sua coleção que você deseja trocar:" << endl;
			cin >> cartasCedidas;

			cout << "Ótimo! Agora Digite os id's também separados por vírgula das figurinhas que você deseja adquirir:" << endl;
			cin >> cartasRecebidas;

			stringstream sc(cartasCedidas);
			stringstream sr(cartasRecebidas);

			while (getline(sc, temp, ','))
			{
				cedidas.push_back(trim(temp));
			}

			while (getline(sr, temp, ','))
			{
				recebidas.push_back(trim(temp));
			}

			for (int i = 0; i < figurinhas.size(); i++)
			{
				for (int j = 0; j < recebidas.size(); j++)
				{
					if (figurinhas[i].getId() == stoi(recebidas[j]))
					{
						Figurinha tempFig(figurinhas[i].getId(), figurinhas[i].getCodigo(), figurinhas[i].getTitulo(), figurinhas[i].getSecao(), figurinhas[i].getTipo());

						result.push_back(tempFig);
					}
				}
			}

			user.trocarFigurinhas(cedidas, result);

			break;
		}
		case 4:
		{
			user.mostrarAlbum();
			cout << "\n";
			break;
		}
		default:
		{
			cout << "\nPrograma encerrado.\n";
			exit(0);
		} // end switch
		}
	} while (true); // end do...while
}
