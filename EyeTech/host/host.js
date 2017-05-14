/**
* 整理host文件
*/

const fs = require('fs');
const path = require('path');
const readline = require('readline');

let fRead = fs.createReadStream('./data.txt'),
	fWrite = fs.createWriteStream('./output.txt');

let rl = readline.createInterface({
	input: fRead
});

let host_ip = {}, ip_host = {};

rl.on('line', line => {
	let tmp = line.trim().split(' ');
	host_ip[tmp[1]] = tmp[0];
})

rl.on('close', () => {
	for(key in host_ip){
		if(!(host_ip[key] in ip_host)) ip_host[host_ip[key]] = [];
		ip_host[host_ip[key]].push(key);
	}
	for(key in ip_host){
		fWrite.write(key + ' ' + ip_host[key] + '\n');
	}
	console.log('realine close...');

	process.stdin.resume(); // 标准输入流默认是暂停pause的，所以必须要调用process.stdin.resume()来恢复resume接收
	process.stdin.on('data', chunk => {
		let key = chunk.toString().trim();
		console.log('Result: ', ip_host[key]);
	})
	console.log('input search keyword：');
})


