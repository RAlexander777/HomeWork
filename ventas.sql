-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 09-06-2019 a las 00:32:52
-- Versión del servidor: 10.1.37-MariaDB
-- Versión de PHP: 7.3.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `ventas`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `boleta`
--

CREATE TABLE `boleta` (
  `NUM_BOLETA` int(11) NOT NULL,
  `FECHA` date NOT NULL,
  `ID_CLIENTE` char(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `boleta`
--

INSERT INTO `boleta` (`NUM_BOLETA`, `FECHA`, `ID_CLIENTE`) VALUES
(1, '2015-01-10', 'C0011'),
(2, '2015-01-20', 'C0002'),
(3, '2015-01-20', 'C0001'),
(4, '2015-01-23', 'C0005'),
(5, '2015-02-10', 'C0001'),
(6, '2015-02-20', 'C0002'),
(7, '2015-03-05', 'C0006'),
(8, '2015-03-24', 'C0006'),
(9, '2015-04-20', 'C0005'),
(10, '2015-04-20', 'C0011'),
(11, '2015-05-10', 'C0006'),
(12, '2015-06-20', 'C0006'),
(13, '2015-07-20', 'C0001'),
(14, '2015-07-26', 'C0006'),
(15, '2015-07-20', 'C0006'),
(16, '2015-07-20', 'C0005'),
(17, '2015-08-10', 'C0002'),
(18, '2015-09-05', 'C0012'),
(19, '2015-10-20', 'C0006'),
(20, '2015-11-27', 'C0014'),
(21, '2015-11-05', 'C0002'),
(22, '2015-11-20', 'C0001');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cliente`
--

CREATE TABLE `cliente` (
  `ID_CLIENTE` char(5) NOT NULL,
  `NOMBRES` varchar(30) NOT NULL,
  `PATERNO` varchar(30) NOT NULL,
  `MATERNO` varchar(30) NOT NULL,
  `DIRECCION` varchar(40) DEFAULT NULL,
  `FONO` char(15) DEFAULT NULL,
  `ID_DISTRITO` char(3) NOT NULL,
  `EMAIL` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `cliente`
--

INSERT INTO `cliente` (`ID_CLIENTE`, `NOMBRES`, `PATERNO`, `MATERNO`, `DIRECCION`, `FONO`, `ID_DISTRITO`, `EMAIL`) VALUES
('C0001', 'CARLOS', 'LOPEZ', 'HURTADO', 'Calle El Pino 346', '4677352', 'L01', 'clopez@hotmail.com'),
('C0002', 'FRIDA', 'QUIROZ', 'DUARTE', 'Jr. Los Reyes 475 ', '6734732', 'L06', 'fquiroz@peru.com'),
('C0003', 'ALEJANDRO', 'TRAUCO', 'MANRIQUE', 'Jr.Huascar 956', '4676732', 'L04', 'atruco@gmail.com'),
('C0004', 'CARLA', 'BLANCO', 'RUIZ', 'Av. Arequipa 451', '4867438', 'L03', 'cblanco@hotmail.com'),
('C0005', 'CORINA', 'MENDOZA', 'PEREZ', 'Av. Ingenierios 111', '2548965', 'L09', 'cmendoza@hotmail.com'),
('C0006', 'JORGE', 'RODAS', 'DIONICIO', 'Jr. Las Liras 456', '4789658', 'L03', 'jrodas@gmail.com'),
('C0007', 'ORLANDO', 'CUEVAS', 'CABANILLAS', 'Calle La Encantada 425', '5698532', 'L11', 'ocuevas@peru.com'),
('C0008', 'ANTUANE', 'RODRIGUEZ', 'ALARCON', 'Av. Dorado 347', '4589732', 'L05', 'arodriguez@hotmail.com'),
('C0009', 'MANUEL', 'SUAREZ', 'FERNANDEZ', 'Jr. Los Robles 854', '4576738', 'L19', 'msuarez@gmail.com'),
('C0010', 'JUAN', 'GUTIERREZ', 'DIAZ', 'Calle Girasoles 456', '4897421', 'L14', 'jgutierrez@hotmail.com'),
('C0011', 'CARLOS', 'COLAN', 'BARDALES', 'Av. Los H?roes 895', '3698574', 'L19', 'ccolan@peru.com'),
('C0012', 'MARTIN', 'CARRILLO', 'SALAS', 'Calle Los Huertos 844', '8965952', 'L08', 'mcarrillo@gmail.com'),
('C0013', 'JOSE', 'LAZARTE', 'LUJAN', 'Jr. Agapito 452', '1258965', 'L17', 'jlazarte@gmail.com'),
('C0014', 'VIDAL', 'ZORRILLA', 'RODRIGUEZ', 'Av. H?roes del cenepa 635', '1547894', 'L20', 'vzorrilla@hotmail.com'),
('C0015', 'GUILLERMO', 'RAMOS', 'FLORES', 'Jr. Las Almendras 211', '4587964', 'L03', 'gramos@gmail.com');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalleboleta`
--

CREATE TABLE `detalleboleta` (
  `NUM_BOLETA` int(11) NOT NULL,
  `ID_PRODUCTO` char(5) NOT NULL,
  `CANTIDAD` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `detalleboleta`
--

INSERT INTO `detalleboleta` (`NUM_BOLETA`, `ID_PRODUCTO`, `CANTIDAD`) VALUES
(1, 'P0001', 20),
(1, 'P0005', 10),
(2, 'P0002', 20),
(2, 'P0003', 15),
(2, 'P0005', 10),
(3, 'P0005', 19),
(4, 'P0001', 19),
(4, 'P0003', 11),
(4, 'P0005', 15),
(5, 'P0002', 15),
(5, 'P0005', 10),
(6, 'P0003', 19),
(7, 'P0002', 11),
(8, 'P0001', 10),
(9, 'P0005', 11),
(10, 'P0015', 12),
(11, 'P0002', 11),
(11, 'P0005', 15),
(12, 'P0003', 19),
(12, 'P0015', 15),
(13, 'P0002', 12),
(13, 'P0005', 11),
(14, 'P0005', 19),
(15, 'P0003', 12),
(16, 'P0015', 15),
(17, 'P0001', 21),
(18, 'P0004', 12),
(18, 'P0005', 21),
(19, 'P0004', 15),
(20, 'P0015', 30),
(21, 'P0005', 30),
(22, 'P0001', 30);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `distrito`
--

CREATE TABLE `distrito` (
  `ID_DISTRITO` char(3) NOT NULL,
  `DESCRIPCION` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `distrito`
--

INSERT INTO `distrito` (`ID_DISTRITO`, `DESCRIPCION`) VALUES
('L01', 'CERCADO'),
('L02', 'ANCON'),
('L03', 'ATE'),
('L04', 'BARRANCO'),
('L05', 'BRE?A'),
('L06', 'CARABAYLLO'),
('L07', 'COMAS'),
('L08', 'CHACLACAYO'),
('L09', 'CHORRILLOS'),
('L10', 'EL AGUSTINO'),
('L11', 'JESUS MARIA'),
('L12', 'LA MOLINA'),
('L13', 'LA VICTORIA'),
('L14', 'LINCE'),
('L15', 'LURIGANCHO'),
('L16', 'LURIN'),
('L17', 'MAGDALENA'),
('L18', 'MIRAFLORES'),
('L19', 'PACHACAMAC'),
('L20', 'PUCUSANA');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `ID_PRODUCTO` char(5) NOT NULL,
  `DESCRIPCION` varchar(50) NOT NULL,
  `PRECIO` decimal(8,2) NOT NULL,
  `STOCK` int(11) NOT NULL,
  `FECHA_VENC` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `producto`
--

INSERT INTO `producto` (`ID_PRODUCTO`, `DESCRIPCION`, `PRECIO`, `STOCK`, `FECHA_VENC`) VALUES
('P0001', 'PYE DE MANZANA', '20.00', 500, '2015-05-14'),
('P0002', 'TORTA DE CHOCOLATE', '45.00', 100, '2015-07-04'),
('P0003', 'TORTA TRES LECHES', '30.00', 40, '2015-06-24'),
('P0004', 'MOUSE DE MANZANA', '35.00', 70, '2015-09-06'),
('P0005', 'ARROZ CON LECHE-ENVASE ESPECIAL', '13.00', 40, '2015-11-04'),
('P0006', 'MAZAMORRA MORADA', '1.50', 70, '2015-12-04'),
('P0007', 'YOGURT ARABE', '3.00', 100, '2015-05-04'),
('P0008', 'PAN CON POLLO', '2.00', 500, '2015-06-05'),
('P0009', 'BROWNIE', '3.00', 300, '2015-05-04'),
('P0010', 'BESO DE MOZA', '1.00', 400, '2015-06-03'),
('P0011', 'PYE DE LIMON', '1.70', 100, '2015-05-02'),
('P0012', 'TORTA DE NARANJA', '16.00', 10, '2015-04-07'),
('P0013', 'TORTA DE FRESA', '41.00', 100, '2015-05-07'),
('P0014', 'ALFAJORES', '0.30', 400, '2015-04-06'),
('P0015', 'CHOCOTEJAS', '2.00', 100, '2015-04-14'),
('P0016', 'SUSPIRO A LA LIME?A', '3.50', 100, '2015-06-12');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `boleta`
--
ALTER TABLE `boleta`
  ADD PRIMARY KEY (`NUM_BOLETA`),
  ADD KEY `ID_CLIENTE` (`ID_CLIENTE`);

--
-- Indices de la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`ID_CLIENTE`),
  ADD KEY `ID_DISTRITO` (`ID_DISTRITO`);

--
-- Indices de la tabla `detalleboleta`
--
ALTER TABLE `detalleboleta`
  ADD PRIMARY KEY (`NUM_BOLETA`,`ID_PRODUCTO`),
  ADD KEY `ID_PRODUCTO` (`ID_PRODUCTO`);

--
-- Indices de la tabla `distrito`
--
ALTER TABLE `distrito`
  ADD PRIMARY KEY (`ID_DISTRITO`);

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`ID_PRODUCTO`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `boleta`
--
ALTER TABLE `boleta`
  MODIFY `NUM_BOLETA` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `boleta`
--
ALTER TABLE `boleta`
  ADD CONSTRAINT `boleta_ibfk_1` FOREIGN KEY (`ID_CLIENTE`) REFERENCES `cliente` (`ID_CLIENTE`);

--
-- Filtros para la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD CONSTRAINT `cliente_ibfk_1` FOREIGN KEY (`ID_DISTRITO`) REFERENCES `distrito` (`ID_DISTRITO`);

--
-- Filtros para la tabla `detalleboleta`
--
ALTER TABLE `detalleboleta`
  ADD CONSTRAINT `detalleboleta_ibfk_1` FOREIGN KEY (`ID_PRODUCTO`) REFERENCES `producto` (`ID_PRODUCTO`),
  ADD CONSTRAINT `detalleboleta_ibfk_2` FOREIGN KEY (`NUM_BOLETA`) REFERENCES `boleta` (`NUM_BOLETA`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
