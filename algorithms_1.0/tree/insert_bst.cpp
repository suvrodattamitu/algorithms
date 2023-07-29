//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* rec(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }

        if(root->val < val) {
            root->right = rec(root->right, val);
        } else {
            root->left = rec(root->left, val);
        }

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return rec(root, val);
    }
};

/*

 public function getAdvanceSettings()
    {
        $advanceSettings = (new GlobalSettings())->getGlobalSettings('advance_settings');

        return [
            'message'           => 'success',
            'advance_settings'  => $advanceSettings
       ];
    }

    public function saveAdvanceSettings(Request $request)
    {
        $advanceSettings = $request->get('advance_settings');
        $settings = get_option('wpsr_global_settings', []);
        $settings['global_settings']['advance_settings'] = $advanceSettings;

        $globalSettings = (new GlobalSettings())->formatGlobalSettings($settings);

        update_option('wpsr_global_settings', $globalSettings);

        return [
            'message'   =>  __('Settings saved successfully!', 'wp-social-reviews')
        ];
    }

    public function authApp(Request $request)
    {
        $code = $request->get('code');
        $type = $request->get('type');
        $data = $request->get('data');

        $clientId       = Arr::get($data, 'client_id');
        $clientSecret   = Arr::get($data, 'client_secret');
        $redirectUrl    = Arr::get($data, 'redirect_uri');

        try {
            if($type === 'business') {
                $api_url = 'https://graph.facebook.com/oauth/access_token?';
                $apiUrl = $api_url.'client_id='.$clientId.'&redirect_uri='.$redirectUrl.'&client_secret='.$clientSecret.'&code='.$code;
                $response = wp_remote_post($apiUrl);

                if(is_wp_error($response)) {
                    throw new \Exception($response->get_error_message());
                }

                $data = json_decode(wp_remote_retrieve_body($response), true);
                $access_token = Arr::get($data, 'access_token');
            } else {
                $apiUrl = 'https://api.instagram.com/oauth/access_token?client_id=397160271510042&redirect_uri=https://wpsocialninja.com/api/instagram-basic-display-redirect.php&client_secret=9aa487a552c3505cf80a618578d04c93&code='.$code.'&grant_type=authorization_code';
                $response = wp_remote_post($apiUrl);
                if(is_wp_error($response)) {
                    throw new \Exception($response->get_error_message());
                }
                $data = json_decode(wp_remote_retrieve_body($response), true);
                $sl_access_token = isset($data['access_token']) ? $data['access_token'] : '';

                // generate long live access token
                if( $sl_access_token ) {
                    $url = "https://graph.instagram.com/access_token?grant_type=ig_exchange_token&client_secret=9aa487a552c3505cf80a618578d04c93&access_token={$sl_access_token}";
                    $response = wp_remote_post($url);
                    if(is_wp_error($response)) {
                        throw new \Exception($response->get_error_message());
                    }
                    $data = json_decode(wp_remote_retrieve_body($response), true);
                    $access_token = isset($data['access_token']) ? $data['access_token'] : '';
                    $expires_in   = isset($data['expires_in']) ? $data['expires_in'] : '';
                }

                error_log(print_r($sl_access_token, true));
            }

            if(!empty($access_token)) {
                $settings = [
                    'credentials_type'    =>  ($type === 'basic_display') ? 'personal' : 'business',
                    'api_type'            =>  ($type === 'basic_display') ? 'personal' : 'business',
                    'access_token'        =>  $access_token,
                    'expires_in'          =>  Arr::get($data, 'expires_in'),
                    'user_id'             =>  null,
                    'selectedAccounts'    =>  []
                ];

                //connect this account now as the verification done..
                (new InstagramFeed())->handleCredential($settings);
            }

            $error = Arr::get($data, 'error.message', 'Error!');
            throw new \Exception($error);
        } catch (\Exception $exception) {
            error_log($exception->getMessage());
            wp_send_json_error([
                'message' => $exception->getMessage()
            ], 423);
        }
    }

*/

/*
 if (this.credentialsType === 'personal') {
        window.open('https://api.instagram.com/oauth/authorize?client_id=397160271510042&redirect_uri=https://wpsocialninja.com/api/instagram-basic-display-redirect.php&response_type=code&scope=user_profile,user_media&state=' + this.admin_page_url, '_self');
      }
        let clientId = '397160271510042';
        let redirectUrl = 'https://wpsocialninja.com/api/instagram-basic-display-redirect.php';

<<<<<<< Updated upstream
      if (this.credentialsType === 'business') {
        window.open('https://graph.facebook.com/oauth/authorize?client_id=443259723723907&redirect_uri=https://wpsocialninja.com/api/instagram-graph-api-redirect.php&scope=instagram_basic,pages_read_engagement,pages_show_list&state=' + this.admin_page_url, '_self');
=======
        if(this.appSettings.enable_app === 'yes') {
          clientId = '750162115912167';
          //clientSecret = '747ee07ec179005d56072490f8d8bd5b'
          redirectUrl = 'https://wpsn.test/wp-content/plugins/api/instagram-basic-display-manual-app-login.php';
        }

        window.open('https://api.instagram.com/oauth/authorize?client_id='+ clientId +'&redirect_uri='+ redirectUrl +'&response_type=code&scope=user_profile,user_media&state=' + this.admin_page_url, '_self');
      } else if (this.credentialsType === 'business') {
        let clientId = '443259723723907';
        let redirectUrl = 'https://wpsocialninja.com/api/instagram-graph-api-redirect.php';
        if(this.appSettings.enable_app === 'yes') {
          clientId = this.appSettings.client_id;
          redirectUrl = this.appSettings.redirect_uri;
        }

        window.open('https://graph.facebook.com/oauth/authorize?client_id='+ clientId +'&redirect_uri='+ redirectUrl +'&scope=instagram_basic,pages_read_engagement,pages_show_list&state=' + this.admin_page_url, '_self');
*/

/*
 makeRequest(code) {
      this.$get('settings/auth', {data: this.appSettings, code: code, type: this.type})
          .then(response => {
            if(response) {
              this.getVerificationConfigs();
              this.businessAccountsModal = true;
              this.handleSuccess(response.data.message);
            }
          }).catch((errors) => {
            this.handleError(errors);
          }).always(() => {
            this.code = null;
           // window.history.pushState({}, null, this.admin_page_url);
          });
*/

//  const queryString = window.location.search;
//       const urlParams = new URLSearchParams(queryString);
//       this.code = urlParams.get('auth_code');
//       this.type = urlParams.get('type');