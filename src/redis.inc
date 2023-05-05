<?php

	$redis = new Redis() or die("no va");
	
	$redis->connect( '172.23.184.244' , 6379 );
	//$redis->auth(['redis', 'redis']);
	//phpinfo();
	
	//echo $redis->ping();
	
	//print_r($redis->acl('USERS'));
	$redis->expire( 'p2', 10 );
	
	echo $redis->get( 'p2' );
