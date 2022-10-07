exports.handler = async (event, context, callback) => {
    const authCode = event.authorizationToken;
    
    if (authCode == 'myserversauthfunction1233212719sakladnme') {
        const policy = {
            Version: '2012-10-17',
            Statement: []
        };
        
        const statementOne = {
            Action: 'execute-api:Invoke',
            Effect: 'Allow',
            Resource: event.methodArn
        };
        
        policy.Statement.push(statementOne);
        
        const response = {
            principalId: 'user',
            policyDocument: policy
        };
        
        callback(null, response);
    }
    else {
        callback('Unauthorized');
    }
};